//
// Created by newap on 9/20/2020.
//

#include "charlib.h"

size_t mstrlen(const char *str) {
    if (str == nullptr)
        return 0;

    size_t i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

size_t mstrlen(const wchar_t *str) {
    size_t i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *mstrncpy(char *destination, const char *source, size_t num) {
    size_t i;

    for (i = 0; i < num && source[i] != '\0'; i++)
        destination[i] = source[i];
    for (; i < num; i++)
        destination[i] = '\0';

    return destination;
}

char *mstrcpy(char *destination, const char *source) {
    size_t i;

    for (i = 0; source[i] != '\0'; i++)
        destination[i] = source[i];

    return destination;
}

wchar_t *mstrcpy(wchar_t *destination, const wchar_t *source) {
    size_t i;

    for (i = 0; source[i] != '\0'; i++)
        destination[i] = source[i];

    return destination;
}

char *mstrncat(char *destination, const char *source, size_t num) {
    size_t destination_len = mstrlen(destination), i;

    for (i = 0; i < num && source[i] != '\0'; i++)
        destination[destination_len + i] = source[i];
    destination[destination_len + i] = '\0';

    return destination;
}

char *mstrcat(char *destination, const char *source) {
    size_t destination_len = mstrlen(destination), i;

    for (i = 0; source[i] != '\0'; i++)
        destination[destination_len + i] = source[i];
    destination[destination_len + i] = '\0';

    return destination;
}

const char *mstrstr(const char *str1, const char *str2) {
    const char *a, *b;

    b = str2;
    if (*b == 0)
        return str1;

    for (; *str1 != 0; str1++) {
        if (*str1 != *b)
            continue;

        a = str1;
        while (true) {
            if (*b == 0)
                return str1;

            if (*a++ != *b++)
                break;
        }
        b = str2;
    }
    return nullptr;
}

char *mstrstr(char *str1, const char *str2) {
    const char *a, *b;

    b = str2;
    if (*b == 0)
        return str1;

    for (; *str1 != 0; str1++) {
        if (*str1 != *b)
            continue;

        a = str1;
        while (true) {
            if (*b == 0)
                return str1;

            if (*a++ != *b++)
                break;
        }
        b = str2;
    }
    return nullptr;
}

char *mstrtok(char *str, const char *delimiters) {
    static char *_buffer;
    if (str != nullptr) _buffer = str;
    if (_buffer[0] == '\0') return nullptr;

    char *ret = _buffer, *b;
    const char *d;

    for (b = _buffer; *b != '\0'; b++) {
        for (d = delimiters; *d != '\0'; d++) {
            if (*b == *d) {
                *b = '\0';
                _buffer = b + 1;

                if (b == ret) {
                    ret++;
                    continue;
                }
                return ret;
            }
        }
    }

    return ret;
}

int mstrcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2))
        str1++, str2++;

    return (str1 == str2) ? 0 : (str1 < str2) ? -1 : 1;
}

int mstrcmp(const wchar_t *str1, const wchar_t *str2) {
    while (*str1 && (*str1 == *str2))
        str1++, str2++;

    return (str1 == str2) ? 0 : (str1 < str2) ? -1 : 1;
}


int mbstrcmp(const wchar_t *str1, const wchar_t *str2) {
    size_t len1 = mstrlen(str1), len2 = mstrlen(str2);
    str1 += len1 - 1;
    str2 += len2 - 1;

    while (*str1 && (*str1 == *str2))
        str1--, str2--;

    return (str1 == str2) ? 0 : (str1 < str2) ? -1 : 1;
}

int mbstrcmp(const char *str1, const char *str2) {
    size_t len1 = mstrlen(str1), len2 = mstrlen(str2);
    str1 += len1 - 1;
    str2 += len2 - 1;

    while (*str1 && (*str1 == *str2))
        str1--, str2--;

    return (str1 == str2) ? 0 : (str1 < str2) ? -1 : 1;
}



