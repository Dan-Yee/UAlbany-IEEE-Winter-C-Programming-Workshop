#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

/* Specifications on the implementation of a LinkedList */

/**
 * Struct representing a Node in a LinkedList
 */
struct ListNode {
    int value;
    struct ListNode* next;
};

/**
 * Struct representing a LinkedList of ListNode's
 */
struct LinkedList {
    struct ListNode* head;
    struct ListNode* tail;
    size_t listSize;
};

/**
 * Create a new LinkedList given an initial size
 */
void createLinkedList(struct LinkedList*, size_t);

/**
 * Return the size of the LinkedList
 */
size_t size(struct LinkedList);

/**
 * Return the value of the node at the given index
 */
int get(struct LinkedList*, int);

/**
 * Sets the element at a given index to the given element value
 */
void set(struct LinkedList*, int, int);

/**
 * Function that appends an element to the end of the LinkedList
 */
void add(struct LinkedList*, int);

/**
 * Delete the LinkedList by freeing each Node individually
 */
void deleteLinkedList(struct LinkedList*);

/**
 * Function to display the LinkedList
 */
void displayLinkedList(struct LinkedList*);

#endif