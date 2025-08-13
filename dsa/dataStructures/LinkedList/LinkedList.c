#include "LinkedList.h"
#include "stdlib.h"
#include "stdio.h"

// Add a node in the end of the LinkedList
void addAtLast(LinkedList *ls, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    // If linkedList is empty then make head and tail = newNode
    if (!(ls->head))
    {
        ls->head = ls->tail = newNode;
    }
    else
    {
        ls->tail->next = newNode;
        ls->tail = newNode;
    }
    // Maintaining the length of LinkedList
    ls->length++;
    return;
};

void addAtBegging(LinkedList *ls, int data)
{
    // Simply add a newNode at the start point of LinkedLIst

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!(ls->head))
    {
        ls->head = ls->tail = newNode;
    }
    else
    {
        newNode->next = ls->head;
        ls->head = newNode;
    }
    ls->length++;
}

void reverseList(LinkedList *ls)
{
    // To reverse the list we will point every node to previous node
    //  Also we swap the head and tail

    if (ls->head == NULL || !(ls->head))
    {
        printf("No data found to Reverse\n");
        return;
    };

    Node *prev = NULL;
    Node *current = ls->head;
    Node *next = NULL;
    ls->tail = ls->head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    ls->head = prev;
}

void deleteStartingNode(LinkedList *ls)
{
    if (ls->head == NULL || !(ls->head))
    {
        printf("No Node found to delete");
        return;
    }
    Node *temp = ls->head;
    ls->head = ls->head->next;
    free(temp);
    return;
}

void deleteEndingNode(LinkedList *ls)
{
    if (ls->tail == NULL || !(ls->tail))
    {
        printf("No Node found to delete");
        return;
    }

    Node *temp = ls->tail;

    ls->tail = NULL;
    free(temp);
    return;
}

void printList(LinkedList *ls)
{
    if (ls->head == NULL)
    {
        printf("No data found in Linked List\n");
        return;
    };
    Node *current = ls->head;
    int i = 1;

    // This will print data of every node in linkedList
    while (current != NULL)
    {
        printf("%d. Data => %d\n", i, current->data);
        current = current->next;
        i++;
    }
    return;
}