#include "strings.h"

void stringCompareHelper(const char* string1, const char* string2) {
    switch(stringCompare(string1, string2)) {
        case -1:
            printf("\"%s\" is less than \"%s\".\n", string1, string2);
            break;
        case 0:
            printf("\"%s\" is equal to \"%s\".\n", string1, string2);
            break;
        case 1:
            printf("\"%s\" is greater than \"%s\".\n", string1, string2);
            break;
        default:
            printf("Invalid Strings in stringCompare(const char* string1, const char* string2)\n");
            break;
    }
}

int main(int argc, char** argv) {
    printf("\n<< Testing stringLength Implementation >>\n");
    const char* helloWorld = "Hello World!";
    printf("The length of the string \"%s\" is %d.\n", helloWorld, stringLength(helloWorld));


    printf("\n<< Testing stringCompare Implementation >>\n");
    const char* string1 = "UAlbany IEEE";
    const char* string2 = "Emperor James Oswald";
    stringCompareHelper(string1, string2);

    const char* string3 = "Hello";
    const char* string4 = "Hello";
    stringCompareHelper(string3, string4);

    const char* string5 = "Bruh";
    const char* string6 = "Meme";
    stringCompareHelper(string5, string6);

    printf("\n<< Testing stringCopy Implementation >>\n");
    char* result = (char*)malloc(6 * sizeof(char));
    const char* source = "Ubuntu";

    printf("Result before Copy is \"%s\"\n", result);
    printf("Copy \"%s\" into Result...\n", source);
    stringCopy(result, source);
    printf("Result after Copy is \"%s\"\n", result);
    free(result);

    printf("\n<< Testing stringDuplicate Implementation >>\n");
    const char* source2 = "Facebook_Google_YouTube";
    char* duplicated = "";

    printf("Value of variable \"duplicated\" is \"%s\"\n", duplicated);
    printf("Duplicate \"%s\" into \"duplicated\"...\n", source2);
    duplicated = stringDuplicate(source2);
    printf("Value of variable \"duplicated\" is \"%s\"\n", duplicated);
    free(duplicated);

    printf("\n<< Testing stringConcat Implementation >>\n");
    char string7[50] = "Hello";
    const char* string8 = " World!";
    
    printf("Value of variable \"string7\" is \"%s\"\n", string7);
    printf("Value of variable \"string8\" is \"%s\"\n", string8);
    printf("Concatenate \"%s\" onto \"%s\"...\n", string8, string7);
    stringConcat(string7, string8);
    printf("Value of variable \"string7\" is \"%s\"\n", string7);

    return 0;
}
