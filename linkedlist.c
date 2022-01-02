#include <stdio.h>
#include <stdlib.h>

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
 * If initial size is 0, list is empty and head and tail point to null
 * If initial size is less than 0, do nothing and print error message
 * Otherwise, initialize the head as a ListNode and link as many nodes as needed until the list size is equal to initial size
 */
void createLinkedList(struct LinkedList* list, size_t initialSize) {
    if(initialSize == 0) {
        list->head = NULL;
        list->tail = NULL;
        list->listSize = initialSize;
    } else if(initialSize < 0)
        printf("Error: Initial size cannot be less than zero.\n");
    else {
        list->head = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* currentNode = list->head;
        list->listSize = initialSize;

        for(int i = 1; i < initialSize; i++) {
            if(i == initialSize - 1)
                list->tail = currentNode;
            currentNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));          // set the next node of the current to a blank tempNode
            currentNode = currentNode->next;                                                // "traverse" to the next node of the LinkedList
        }
    }
}

/**
 * Return the size of the LinkedList
 */
size_t size(struct LinkedList list) {
    return list.listSize;
}

/**
 * Loop through the LinkedList until the given index and return the value of the node at the index
 */
int get(struct LinkedList* list, int index) {
    if(list->head != NULL) {
        struct ListNode* currentNode = list->head;

        for(int i = 0; i < index; i++)
            currentNode = currentNode->next;
        return currentNode->value;
    } else
        return -1;
}

/**
 * Function that sets the element at a given index to the given element value if the index is not out of bounds
 * If the list size is 0, print and error message
 */
void set(struct LinkedList* list, int index, int element) {
    if(list->listSize != 0) {
        if(!(index < 0 || index > list->listSize)) {
            struct ListNode* currentNode = list->head;
            int currentNodeCount = 0;

            while(currentNodeCount != index) {
                currentNode = currentNode->next;
                currentNodeCount++;
            }
            currentNode->value = element;
            printf("\"%d\" was set to index %d\n", element, index);
        } else
            printf("Error: Index out of bounds for LinkedList\n");
    } else
        printf("Error: LinkedList size is 0\n");
}

/**
 * Function that appends an element to the end of the LinkedList
 * If the list size is 0, create the tail node and point the head towards it and incremement the list size
 * If the list size is not 0, create a new node and point the tail towards it and incremement the list size
 */
void add(struct LinkedList* list, int element) {
    if(list->listSize == 0) {
        list->tail = (struct ListNode*)malloc(sizeof(struct ListNode));
        list->tail->value = element;
        list->head = list->tail;
    } else {
        struct ListNode* lastNode = list->tail;
        struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        tempNode->value = element;
        lastNode->next = tempNode;
        list->tail = lastNode->next;
    }
    list->listSize++;
    printf("\"%d\" was added to the LinkedList\n", element);
}

/**
 * Delete the LinkedList by freeing each Node individually
 */
void deleteLinkedList(struct LinkedList* list) {
    struct ListNode* currentNode = list->head;
    struct ListNode* tempNode;

    if(list->listSize != 0) {
        do {
            tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        } while(currentNode != NULL);
    }
}

/**
 * Function to display all the Nodes starting from the head
 */
void displayLinkedList(struct LinkedList* list) {
    struct ListNode* currentNode = list->head;

    if(currentNode != NULL) {
        do {
            printf("Node Value: %d\n", currentNode->value);
            currentNode = currentNode->next;
        } while(currentNode != NULL);
    } else
        printf("List is empty\n");
}

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