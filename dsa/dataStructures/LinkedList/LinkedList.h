#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int length;
} LinkedList;

void addAtLast(LinkedList *ls, int data);
void addAtBegging(LinkedList *ls, int data);
void reverseList(LinkedList *ls);
void printList(LinkedList *ls);
void deleteStartingNode(LinkedList *ls);
void deleteEndingNode(LinkedList *ls);

#endif