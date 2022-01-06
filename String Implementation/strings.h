#include <stdio.h>
#include <stdlib.h>

#ifndef STRINGS_HEADER
#define STRINGS_HEADER

int stringLength(const char*);

int stringCompare(const char*, const char*);

char* stringCopy(char*, const char*);

char* stringDuplicate(const char*);

char* stringConcat(char*, const char*);

#endif
