#include <stdio.h>

// Question 1.1) Write a define macro that gives the max of two arbitrary numeric tokens
#define MAX(A, B) (A > B) ? A : B

// Question 1.2) Write a define macro that generates a typical for loop over a single statement
#define FOR(VARIABLE_NAME, SIZE, STATEMENT) for(int VARIABLE_NAME = 0; VARIABLE_NAME < SIZE; VARIABLE_NAME++) {STATEMENT;}

int main(int argc, char** argv) {
    printf("Define macro that returns the max of two arbitrary numbers\n");
    int a = 10;
    int b = 5;
    int c = MAX(a, b);

    printf("Integer Test: a = 10, b = 5, c = MAX(a, b)\n");
    printf("c = %d\n", c);

    float fa = 3.141593;
    float fb = 3.141594;
    float fc = MAX(fa, fb);

    printf("Float Test: a = 3.141593, b = 3.141594, c = MAX(a, b)\n");
    printf("fc = %f\n", fc);

    printf("\nDefine macro that creates a For Loop statement\n");
    printf("Test case: Execute printf(\"Hello World!\"); 5 times with variable named x\n");
    FOR(x, 5, printf("Hello World\n"));
}