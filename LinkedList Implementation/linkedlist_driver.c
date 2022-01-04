#include "linkedlist.h"

/* Testing LinkedList implementation */

/**
 * Driver class to test LinkedList implementation
 */
int main(int argc, char** argv) {
    struct LinkedList linkedlist;

    printf("Creating a LinkedList of size 5...\n");
    createLinkedList(&linkedlist, 5);

    printf("\nThe size of the LinkedList is %ld\n", size(linkedlist));

    printf("\nSetting first five elements...\n");
    for(int i = 2; i <= 10; i += 2)
        set(&linkedlist, (i / 2 - 1), i * i);

    printf("\nDisplaying LinkedList...\n");
    displayLinkedList(&linkedlist);

    printf("\nAdding five more elements...\n");
    for(int j = 12; j <= 20; j += 2)
        add(&linkedlist, j * j);

    printf("\nDisplaying LinkedList...\n");
    displayLinkedList(&linkedlist);

    printf("\nDeleting the LinkedList...\n");
    deleteLinkedList(&linkedlist);

    printf("\n=========================\n");
    struct LinkedList linkedlist2;

    printf("Creating a LinkedList of size 0...\n");
    createLinkedList(&linkedlist2, 0);

    printf("\nThe size of the LinkedList is %ld\n", size(linkedlist2));
    
    printf("\nDisplaying LinkedList...\n");
    displayLinkedList(&linkedlist2);

    printf("\nAdding 5 elements to empty LinkedList...\n");
    for(int i = 1; i <= 5; i++)
        add(&linkedlist2, i * 2);

    printf("\nDisplaying LinkedList...\n");
    displayLinkedList(&linkedlist2);

    printf("\nThe size of the LinkedList is %ld\n", size(linkedlist2));

    printf("\nDeleting the LinkedList...\n");
    deleteLinkedList(&linkedlist2);
}