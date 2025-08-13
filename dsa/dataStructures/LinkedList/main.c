#include <stdio.h>
#include "LinkedList.h"
#include "stdlib.h"

// Implementing Singly LinkedList

int main(int argc, char const *argv[])
{
    LinkedList ls = {.head = NULL, .length = 0, .tail = NULL};
    addAtBegging(&ls, 23);
    addAtBegging(&ls, 93);
    addAtBegging(&ls, 28);

    addAtLast(&ls, 81);
    addAtLast(&ls, 91);
    addAtLast(&ls, 67);

    printf("Before reverse\n");
    printList(&ls);
    
    printf("After reverse\n");
    reverseList(&ls);
    printList(&ls);

    return 0;
}