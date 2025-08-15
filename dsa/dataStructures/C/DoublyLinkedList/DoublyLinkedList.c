#include <stdio.h>
#include "DoublyLinkedList.h"

void addAtLast(DoublyLinkedList *ls, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!(ls->head))
    {
        ls->head = ls->tail = newNode;
    }
    else
    {
        ls->tail->next = newNode;
        newNode->prev = ls->tail;
        ls->tail = newNode;
    }

    ls->length++;
    return;
};

void addAtBegging(DoublyLinkedList *ls, int data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!(ls->head))
    {
        ls->head = ls->tail = newNode;
    }
    else
    {
        newNode->next = ls->head;
        ls->head->prev = newNode;
        ls->head = newNode;
    }
    ls->length++;
}

void reverseList(DoublyLinkedList *ls)
{
    Node *current = ls->head;
    Node *next = NULL;
    ls->tail = ls->head;
    Node *temp;
    while (current->next != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        ls->head = temp->prev;
}
