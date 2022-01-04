#include "arraylist.h"

/* Driver class for testing ArrayList implementation */

int main(int argc, char** argv) {
    struct ArrayList list;

    printf("Create new ArrayList of size 10\n");
    createArrayList(&list, 10);

    printf("\nSet all ArrayList elements\n");
    for(int i = 2; i <= 20; i += 2)
        set(&list, ((i / 2) - 1), i * i);

    printf("\nGet all ArrayList elements\n");
    for(int j = 0; j < size(list); j++)
        printf("The element at index %d is \"%d\"\n", j, get(&list, j));

    printf("\nAdd \"1000\" to the end of the ArrayList\n");
    add(&list, 1000);

    printf("\nGet all ArrayList elements\n");
    for(int j = 0; j < size(list); j++)
        printf("The element at index %d is \"%d\"\n", j, get(&list, j));

    printf("\nDeleting the ArrayList\n");
    deleteArrayList(&list);
}