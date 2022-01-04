#include <stdio.h>
#include <stdlib.h>

/* Specifications on the implementation of ArrayList functions */

#ifndef ARRAYLIST_HEADER
#define ARRAYLIST_HEADER

struct ArrayList {
    size_t listSize;
    int* arrayList;
};

/**
 * Void function that creates an "ArrayList" by mallocing an array of size initialSize
 */
void createArrayList(struct ArrayList*, size_t);

/**
 * size_t function that returns the size of the ArrayList created
 */
size_t size(struct ArrayList);

/**
 * Void function that updates the element at a given index in the ArrayList to a new specified element
 */
void set(struct ArrayList*, int, int);

/**
 * int function that returns the element at a given index in the ArrayList
 */
int get(struct ArrayList*, int );

/**
 * Void function that appends a specified element to the end of the ArrayList
 */
void add(struct ArrayList*, int);

/**
 * Void function that deletes the ArrayList by freeing all dynamically allocated memory
 */
void deleteArrayList(struct ArrayList*);

#endif