#include "strings.h"

#define MAX(A, B) (A > B) ? A : B

int stringLength(const char* string) {
    int length = 0;

    while(string[length] != '\0')
        length++;
    return length;
}

int stringCompare(const char* string1, const char* string2) {
    int maxLength = MAX(stringLength(string1), stringLength(string2));

    for(int i = 0; i < maxLength; i++) {
        if(string1[i] < string2[i])
            return -1;
        else if(string1[i] > string2[i])
            return 1;
    }
    return 0;
}

char* stringCopy(char* destination, const char* string) {
    for(int i = 0; i < stringLength(string); i++)
        destination[i] = string[i];
    return destination;
}

char* stringDuplicate(const char* string) {
    char* duplicated = (char*)malloc(stringLength(string) * sizeof(char));
    
    for(int i = 0; i < stringLength(string); i++)
        duplicated[i] = string[i];
    return duplicated;
}

char* stringConcat(char* string1, const char* string2) {
    int secondIndex;
    char* concatenated = (char*)malloc((stringLength(string1) + stringLength(string2)) * sizeof(char));
    concatenated = stringCopy(concatenated, string1);

    for(int i = 0, j = stringLength(string1); i < stringLength(string2) && j < (stringLength(string1) + stringLength(string2)); i++, j++)
        concatenated[j] = string2[i];
    concatenated[(stringLength(string1) + stringLength(string2))] = '\0';
    return concatenated;
}