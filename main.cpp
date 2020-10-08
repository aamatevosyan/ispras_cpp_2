#include <iostream>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <codecvt>
#include "charlib.h"
#include <vector>

using namespace std;

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

void test_mstrlen() {
    printf("%s\n", "test_mstrlen");

    assert(mstrlen("hello") == 5);
    assert(mstrlen("") == 0);

    printf("\n");
}

void test_mstrcpy() {
    printf("%s\n", "test_mstrcpy");

    char str1[] = "Sample string";
    char str2[40];
    char str3[40];
    mstrcpy(str2, str1);
    mstrcpy(str3, "copy successful");
    printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

    printf("\n");
}

void test_mstrncpy() {
    printf("%s\n", "test_mstrncpy");

    char str1[] = "To be or not to be";
    char str2[40];
    char str3[40];

    /* copy to sized buffer (overflow safe): */
    mstrncpy(str2, str1, sizeof(str2));

    /* partial copy (only 5 chars): */
    mstrncpy(str3, str2, 5);
    str3[5] = '\0';   /* null character manually added */

    puts(str1);
    puts(str2);
    puts(str3);

    printf("\n");
}

void test_mstrcat() {
    printf("%s\n", "test_mstrcat");

    char str[80];
    mstrcpy(str, "these ");
    mstrcat(str, "strings ");
    mstrcat(str, "are ");
    mstrcat(str, "concatenated.");
    puts(str);

    printf("\n");
}

void test_mstrncat() {
    printf("%s\n", "test_mstrncat");

    char str1[20];
    char str2[20];
    mstrcpy(str1, "To be ");
    mstrcpy(str2, "or not to be");
    mstrncat(str1, str2, 6);
    puts(str1);

    printf("\n");
}

void test_mstrstr() {
    printf("%s\n", "test_mstrstr");

    char str[] = "This is a simple string";
    char *pch;
    pch = mstrstr(str, "simple");
    mstrncpy(pch, "sample", 6);
    puts(str);

    printf("\n");
}

void test_mstrtok() {
    printf("%s\n", "test_mstrtok");

    char str[] = "- This, a sample string.";
    char *pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = mstrtok(str, " ,.-");
    while (pch != nullptr) {
        printf("%s\n", pch);
        pch = mstrtok(nullptr, " ,.-");
    }

    printf("\n");
}

void test_mstrcmp() {
    printf("%s\n", "test_mstrcmp");

    char a[] = "apple";
    char b[] = "apple";
    char c[] = "peach";

    printf("%d\n", mstrcmp(a, b));
    printf("%d\n", mstrcmp(a, c));
    printf("%d\n", mstrcmp(c, b));

    printf("\n");
}

void test_mbstrcmp() {
    printf("%s\n", "test_mbstrcmp");

    char a[] = "applez";
    char b[] = "applez";
    char c[] = "peach";

    printf("%d\n", mbstrcmp(a, b));
    printf("%d\n", mbstrcmp(a, c));
    printf("%d\n", mbstrcmp(c, b));

    printf("\n");
}

void test_all() {
    test_mstrlen();
    test_mstrcpy();
    test_mstrncpy();
    test_mstrcat();
    test_mstrncat();
    test_mstrstr();
    test_mstrtok();
    test_mstrcmp();
    test_mbstrcmp();
}

struct masc {
    inline bool operator()(const string &a, const string &b) {
        for (size_t i = 0, j = 0; i < a.length() || j < b.length();) {
            while (ispunct(a[i]) || isspace(a[i]))
                i++;

            while (ispunct(b[j]) || isspace(b[j]))
                j++;

            if (tolower(a[i]) == tolower(b[j]))
                i++, j++;
            else
                return tolower(a[i]) < tolower(b[j]);
        }
        return false;
    }
};

struct mdes {
    inline bool operator()(const string &a, const string &b) {
        for (size_t i = a.length() - 1, j = b.length() - 1; (i >= 0 || j >= 0);) {
            while (ispunct(a[i]) || isspace(a[i]))
                i--;

            while (ispunct(b[j]) || isspace(b[j]))
                j--;

            if (tolower(a[i]) == tolower(b[j]))
                i--, j--;
            else
                return tolower(a[i]) < tolower(b[j]);
        }
        return false;
    }
};

template<typename T>
void sortAndSaveTo(const char *filename, const char *pathToSave, T comparator) {
    ifstream file(filename);
    vector<string> lines;
    string str;

    while (getline(file, str)) {
        string trimmed = trim_copy(str);
        if (str.length() != 0)
            lines.push_back(str);
    }
    file.close();

    sort(lines.begin(), lines.end(), comparator);

    ofstream fout(pathToSave);
    for (auto & line : lines) {
        fout << line << endl;
    }
    fout.close();
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    locale::global(locale());
    wcin.imbue(locale());
    wcout.imbue(locale());

    test_all();

    sortAndSaveTo("../hamlet.txt", "../hamlet-asc.txt", masc());
    sortAndSaveTo("../hamlet.txt", "../hamlet-des.txt", mdes());

    sortAndSaveTo("../onegin.txt", "../onegin-asc.txt", masc());
    sortAndSaveTo("../onegin.txt", "../onegin-des.txt", mdes());

    return 0;
}
