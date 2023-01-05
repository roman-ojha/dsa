#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        preOrder(root->left);
        preOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root, *first, *second, *third, *fourth, *fifth, *sixth;
    root = newNode(11);
    first = newNode(12);
    second = newNode(13);
    third = newNode(14);
    fourth = newNode(15);
    fifth = newNode(18);
    sixth = newNode(17);
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->left = fifth;
    second->right = sixth;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}