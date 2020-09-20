//
// Created by newap on 9/20/2020.
//

#ifndef ISPRAS_CPP_2_CHARLIB_H
#define ISPRAS_CPP_2_CHARLIB_H

#include <cstddef>

/**
 * Returns the length of the C string str.
 * @param str C string.
 * @return The length of string.
 */
size_t mstrlen(const char *str);

/**
 * Copy characters from string
 * @param destination Pointer to the destination array where the content is to be copied.
 * @param source C string to be copied.
 * @param num Maximum number of characters to be copied from source.
 * @return destination is returned.
 */
char *mstrncpy(char *destination, const char *source, size_t num);

/**
 * Copy characters from string
 * @param destination Pointer to the destination array where the content is to be copied.
 * @param source C string to be copied.
 * @return destination is returned.
 */
char *mstrncpy(char *destination, const char *source);

/**
 * Concatenate strings
 * @param destination Pointer to the destination array, which should contain a C string,
 * and be large enough to contain the concatenated resulting string.
 * @param source C string to be appended. This should not overlap destination.
 * @return destination is returned.
 */
char *mstrcat(char *destination, const char *source);

/**
 * Concatenate strings
 * @param destination Pointer to the destination array, which should contain a C string,
 * and be large enough to contain the concatenated resulting string.
 * @param source C string to be appended. This should not overlap destination.
 * @param num Maximum number of characters to be appended.
 * @return destination is returned.
 */
char *mstrncat(char *destination, const char *source, size_t num);

/**
 * Locate substring
 * @param str1 C string to be scanned.
 * @param str2 C string containing the sequence of characters to match.
 * @return A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2, or a null
 * pointer if the sequence is not present in str1.
 */
const char *mstrstr(const char *str1, const char *str2);

/**
 * Locate substring
 * @param str1 C string to be scanned.
 * @param str2 C string containing the sequence of characters to match.
 * @return A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2, or a null
 * pointer if the sequence is not present in str1.
 */
char *mstrstr(char *str1, const char *str2);

/**
 * Split string into tokens
 * @param str C string to truncate.
 * @param delimiters C string containing the delimiter characters.
 * @return If a token is found, a pointer to the beginning of the token.
 * Otherwise, a null pointer.
 */
char *mstrtok(char *str, const char *delimiters);

/**
 * Compare two strings
 * @param str1 C string to be compared.
 * @param str2 C string to be compared.
 * @return Returns an integral value indicating the relationship between the strings:
 * return value	indicates
 * <0	the first character that does not match has a lower value in ptr1 than in ptr2
 * 0	the contents of both strings are equal
 * >0	the first character that does not match has a greater value in ptr1 than in ptr2
 */
int mstrcmp(const char *str1, const char *str2);

/**
 * Compare two strings using reverse order
 * @param str1 C string to be compared.
 * @param str2 C string to be compared.
 * @return Returns an integral value indicating the relationship between the strings:
 * return value	indicates
 * <0	the first character that does not match has a lower value in ptr1 than in ptr2
 * 0	the contents of both strings are equal
 * >0	the first character that does not match has a greater value in ptr1 than in ptr2
 */
int mbstrcmp(const char *str1, const char *str2);

#endif //ISPRAS_CPP_2_CHARLIB_H
