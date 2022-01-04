#include "arraylist.h"

/* Implementation of ArrayList functions */

/**
 * Void function that creates an "ArrayList" by mallocing an array of size initialSize
 */
void createArrayList(struct ArrayList* list, size_t initialSize) {
    if(initialSize < 0)
        printf("Error: Initial size cannot be less than zero\n");
    else {
        list->arrayList = (int*)malloc(initialSize * sizeof(int));
        list->listSize = initialSize;
    }
}

/**
 * size_t function that returns the size of the ArrayList created
 */
size_t size(struct ArrayList list) {
    return list.listSize;
}

/**
 * Void function that updates the element at a given index in the ArrayList to a new specified element
 */
void set(struct ArrayList* list, int index, int element) {
    if(index < 0 || index > list->listSize)
        printf("Error: Index out of bounds of ArrayList\n");
    else {
        *(list->arrayList + index) = element;
        printf("\"%d\" was set at index %d\n", element, index);
    }
}

/**
 * int function that returns the element at a given index in the ArrayList
 */
int get(struct ArrayList* list, int index) {
    if(index < 0 || index > list->listSize)
        printf("Error: Index out of bounds of ArrayList\n");
    else
        return *(list->arrayList + index);
}

/**
 * Void function that appends a specified element to the end of the ArrayList
 */
void add(struct ArrayList* list, int element) {
    list->listSize = list->listSize + 1;
    list->arrayList = (int*)realloc(list->arrayList, (list->listSize * sizeof(int)));
    set(list, list->listSize - 1, element);
}

/**
 * Void function that deletes the ArrayList by freeing all dynamically allocated memory
 */
void deleteArrayList(struct ArrayList* list) {
    free(list->arrayList);
}