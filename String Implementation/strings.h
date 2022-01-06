#include <stdio.h>
#include <stdlib.h>

#ifndef STRINGS_HEADER
#define STRINGS_HEADER

/**
 * Calculates the length of a string, ignoring the null terminator character
 */
int stringLength(const char*);

/**
 * Compares two strings
 * Returns -1 if string1 is less than string2, 0 if string 1 is equal to string2, and 1 if string1 is greater than string2
 */
int stringCompare(const char*, const char*);

/**
 * Copys a string into destination
 */
char* stringCopy(char*, const char*);

/**
 * Duplicates a string and returns a pointer to it
 */
char* stringDuplicate(const char*);

/**
 * Concatenates string2 to the end of string1
 */
char* stringConcat(char*, const char*);

#endif