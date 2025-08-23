#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <syscall.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *create(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return create(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node *search(int key, Node *root)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
    {
        return search(key, root->left);
    }
    else if (root->data > key)
    {
        return search(key, root->right);
    }
    return root;
}

// bool delete(int key, Node *root)
// {
// }

Node *findMin(Node *root)
{
    Node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Depth first search

void printPreorder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d", root->data);
    printPreorder(root->left);
    printPreorder(root->left);
}
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d", root->data);
    printInorder(root->left);
}
void printPostorder(Node *root)
{
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->left);
    printf("%d", root->data);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
