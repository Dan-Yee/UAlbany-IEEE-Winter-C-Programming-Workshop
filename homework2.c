#include <stdio.h>
#include <stdbool.h>

// Question 1.1) Construct a function that takes an input float, x, and an integer exponent, n, and computes and returns the float x^n
float exponentIter(float base, int power) {
    float product = 1;

    for(int i = 0; i < power; i++)
        product *= base;
    
    return product;
}

// Question 1.1 completed using recursion
float exponentRecur(float base, int power) {
    if(power == 1)
        return base;
    else 
        return base * exponentRecur(base, power - 1);
}

// Question 1.2) construct a void function that takes a char, c, and an int, n, and prints an n by n square made out of c to the console
void nbynSquare(char c, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

// Question 2.1) Construct a function that performs linear search given a list of 5 unsorted elements and the element to be found
int linearSearch(int list[5], int element) {
    for(int i = 0; i < 5; i++)
        if(list[i] == element)
            return i;
    return -1;
}

// Question 2.1 Bonus) Construct linear search recursively
int linearSearchRecur(int list[5], int listSize, int element) {
    if(listSize == -1)
        return listSize;
    else if(list[listSize - 1] == element)
        return listSize - 1;
    else
        return linearSearchRecur(list, listSize - 1, element);
}

// Question 2.2) Construct a function that performs binary search give a list of 10 sorted elements and the element to be found
int binarySearch(int list[10], int element) {
    int low = 0, high = 10;
    int midpoint;

    while(low <= high) {
        midpoint = low + (high - low) / 2;
        if(list[midpoint] == element)
            return midpoint;
        else if(element < list[midpoint])
            high = midpoint - 1;
        else if(element > list[midpoint])
            low = midpoint + 1;
    }
    return -1;
}

// Question 2.2 Bonus) construct binary search recursively
int binarySearchRecur(int list[10], int low, int high, int element) {
    int midpoint = low + (high - low) / 2;

    if(list[midpoint] == element)
        return midpoint;
    else if(list[midpoint] > element)
        return binarySearchRecur(list, low, midpoint - 1, element);
    else if(list[midpoint] < element)
        return binarySearchRecur(list, midpoint + 1, high, element);
    else
        return -1;
}

// Question 3) Print out all prime numbers up to infinity
void infinityPrime() {
    int value = 2;
    int infinityPlusOne = 100;                                // if you really want to wait idk how many minutes, use this number: 2147483647
    int primeChecker = 2;
    bool isPrime = true;

    while(value <= infinityPlusOne) {
        while(primeChecker <= (value / 2)) {
            if(value % primeChecker == 0) {                   // if divisible by other numbers, it's not prime
                isPrime = false;
                break;
            }
            primeChecker++;
        }

        if(isPrime)
            printf("%d, ", value);
        isPrime = true;
        value++;
        primeChecker = 2;
    }
    printf("\n");
}

int main(int *argc, char **argv) {
    printf("==================================================\n");
    printf("Iterative Exponent Algorithm: (3.141592)^5 = %f\n", exponentIter(3.141592, 5));
    printf("Recursive Exponent Algorithm: (3.141592)^5 = %f\n", exponentRecur(3.141592, 5));

    printf("==================================================\n");
    nbynSquare('#', 10);
    printf("\n");

    printf("==================================================\n");
    int list[5] = {2, 8, 4, 3, 1};
    printf("Linear Search(Iterative): Element with value 3 in list {2, 8, 4, 3, 1} is at index %d\n", linearSearch(list, 3));
    printf("Linear Search(Iterative): Element with value 0 in list {2, 8, 4, 3, 1} is at index %d\n", linearSearch(list, 0));

    printf("\nLinear Search(Recursive): Element with value 3 in list {2, 8, 4, 3, 1} is at index %d\n", linearSearchRecur(list, 5, 3));
    printf("Linear Search(Recursive): Element with value 0 in list {2, 8, 4, 3, 1} is at index %d\n", linearSearchRecur(list, 5, 0));

    printf("==================================================\n");
    int list2[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    printf("Binary Search(Iterative): Element with value 64 in list {1, 2, 4, 8, 16, 32, 64, 128, 256, 512} is at index %d\n", binarySearch(list2, 64));
    printf("Binary Search(Iterative): Element with value 72 in list {1, 2, 4, 8, 16, 32, 64, 128, 256, 512} is at index %d\n", binarySearch(list2, 72));

    printf("\nBinary Search(Recursive): Element with value 64 in list {1, 2, 4, 8, 16, 32, 64, 128, 256, 512} is at index %d\n", binarySearch(list2, 64));
    printf("Binary Search(Recursive): Element with value 72 in list {1, 2, 4, 8, 16, 32, 64, 128, 256, 512} is at index %d\n", binarySearch(list2, 72));

    printf("==================================================\n");
    printf("Prime numbers from 2 to \"infinity\":\n");
    infinityPrime();
}