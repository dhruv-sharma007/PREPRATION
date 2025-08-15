#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
    int length;
} DoublyLinkedList;

void addAtLast(DoublyLinkedList *ls, int data);
void addAtBegging(DoublyLinkedList *ls, int data);
void reverseList(DoublyLinkedList *ls);
void printList(DoublyLinkedList *ls);
void deleteStartingNode(DoublyLinkedList *ls);
void deleteEndingNode(DoublyLinkedList *ls);

#endif