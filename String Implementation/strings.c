#include "strings.h"

#define MIN(A, B) (A < B) ? A : B

/**
 * Calculates the length of a string, ignoring the null terminator character
 */
int stringLength(const char* string) {
    int length = 0;

    while(string[length] != '\0')
        length++;
    return length;
}

/**
 * Compares two strings
 * Returns -1 if string1 is less than string2, 0 if string 1 is equal to string2, and 1 if string1 is greater than string2
 */
int stringCompare(const char* string1, const char* string2) {
    int minLength = MIN(stringLength(string1), stringLength(string2));

    for(int i = 0; i < minLength; i++) {
        if(string1[i] < string2[i])
            return -1;
        else if(string1[i] > string2[i])
            return 1;
    }
    return 0;
}

/**
 * Copys a string into destination
 */
char* stringCopy(char* destination, const char* string) {
    for(int i = 0; i < stringLength(string); i++)
        destination[i] = string[i];
    return destination;
}

/**
 * Duplicates a string and returns a pointer to it
 */
char* stringDuplicate(const char* string) {
    char* duplicated = (char*)malloc(stringLength(string) * sizeof(char));
    
    for(int i = 0; i < stringLength(string); i++)
        duplicated[i] = string[i];
    return duplicated;
}

/**
 * Concatenates string2 to the end of string1
 */
char* stringConcat(char* string1, const char* string2) {
    int string1Length = stringLength(string1);

    for(int i = 0; i < stringLength(string2); i++)
        string1[string1Length + i] = string2[i];
    return string1;
}