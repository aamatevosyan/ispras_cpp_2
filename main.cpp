#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include "charlib.h"

using namespace std;

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

struct masc
{
    inline bool operator() (const char* a, const char* b)
    {
        return mstrcmp(a, b) < 0;
    }
};

struct mdes
{
    inline bool operator() (const char* a, const char* b)
    {
        return mbstrcmp(a, b) < 0;
    }
};

void sort_asc() {
    printf("%s\n", "sort_asc");

    string str, path = "../romandjul.txt";
    ifstream file(path, ifstream::in);
    char ** lines = new char*[80];
    int ind = 0;

    while (getline(file, str)) {
        lines[ind] = new char[mstrlen(str.c_str())];
        mstrcpy(lines[ind], str.c_str());
        ind++;
    }
    file.close();

    sort(lines, lines + ind, masc());

    for (int i = 0; i < ind; i++)
        printf("%s\n", lines[i]);

    printf("\n");
}

void sort_des() {
    printf("%s\n", "sort_des");

    string str, path = "../romandjul.txt";
    ifstream file(path, ifstream::in);
    char ** lines = new char*[80];
    int ind = 0;

    while (getline(file, str)) {
        lines[ind] = new char[mstrlen(str.c_str())];
        mstrcpy(lines[ind], str.c_str());
        ind++;
    }
    file.close();

    sort(lines, lines + ind, mdes());

    for (int i = 0; i < ind; i++)
        printf("%s\n", lines[i]);

    printf("\n");
}

int main() {
    test_all();

    sort_asc();
    sort_des();

    return 0;
}
