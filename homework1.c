#include <stdio.h>
#include <stdbool.h>

// Homework 1 for UAlbany IEEE Winter Workshop Series: Crash Course on the C Programming Language
int main(int *argc, char **argv) {
    // Question 1.2) Print out a truth table for De Morgan's Laws. Show that ((not A) and (not B)) and (not(A or B)) evaluate the same for all four possible combinations of A and B.
    bool A = true;
    bool B = true;
    bool demorgan1 = ((!A) && (!B));
    bool demorgan2 = (!(A || B));

    printf("De' Morgans Laws:\n");
    printf("[A] \t [B] \t [((not A) and (not B))] \t [(not(A or B))]\n");
    printf("%d \t %d \t\t %d \t\t\t %d\n", A, B, demorgan1, demorgan2);

    A = true;
    B = false;
    demorgan1 = ((!A) && (!B));
    demorgan2 = (!(A || B));

    printf("%d \t %d \t\t %d \t\t\t %d\n", A, B, demorgan1, demorgan2);

    A = false;
    B = false;
    demorgan1 = ((!A) && (!B));
    demorgan2 = (!(A || B));

    printf("%d \t %d \t\t %d \t\t\t %d\n", A, B, demorgan1, demorgan2);

    A = false;
    B = true;
    demorgan1 = ((!A) && (!B));
    demorgan2 = (!(A || B));

    printf("%d \t %d \t\t %d \t\t\t %d\n", A, B, demorgan1, demorgan2);

    // Question 2.1) Print the 3rd bit (index 1 is the ones place) of the number 55 using a right shift and bitwise and with a mask
    printf("\n====================================================================================================\n");
    int number = 0b00110111;                    // 55 in binary
    int bit = (number >> 2) & 0b00000001;       // shift right by 2, apply AND mask of 1

    printf("The 3rd bit of 55 is: %d\n", bit);

    // Question 2.2) Negate a number with two's complement using bitwise negation and a +1
    printf("\n====================================================================================================\n");
    int inputtedNumber;
    int negatedNumber;

    printf("Enter a number: ");
    scanf("%d", &inputtedNumber);
    negatedNumber = ~inputtedNumber + 1;
    printf("The negated number is: %d\n", negatedNumber);

    // Question 3.1) Write a two line program that works differently when substituting an i++ with a ++i
    printf("\n====================================================================================================\n");
    int i = 0;
    printf("i++: %d\n", i++);
    i = 0;
    printf("++i: %d\n", ++i);

    // Queston 3.2) Write a program to cmpute the date of Easter Sunday using the algorithm invented by the mathematician Carl Friedrich Gauss
    printf("\n====================================================================================================\n");
    int year;
    int a, b, c, d, e, f, g, h, j, k, m, n, p, r;
    
    printf("Enter a year (YYYY): ");
    scanf("%d", &year);

    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    g = (8 * b + 13) / 25;
    h = (19 * a + b - d - g + 15) % 30;
    j = c / 4;
    k = c % 4;
    m = (a + 11 * h) / 319;
    r = (2 * e + 2 * j - k - h + m + 32) % 7;
    n = (h - m + r + 90) / 25;
    p = (h - m + r + n + 19) % 32;

    printf("In the year %d, Easter Sunday falls on the day %d of month %d of the Gregorian calendar.\n", year, p, n);

    return 0;
}