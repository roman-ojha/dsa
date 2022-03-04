/*
    ->In a Binary Search Tree (BST), all keys in left subtree of a key must be smaller and all keys in right subtree must be greater. So a Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.
*/

#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertation(struct node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        // 'prev' will hold the node of the prev root before changing
        if (key == root->data)
        {
            cout << "Key already exist" << endl;
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *ptr = createNode(key);
    if (key < prev->data)
    {
        // if root data is greater then the key then this statement will apply
        prev->left = ptr;
    }
    else
    {
        // if root data is less then the key then this statement will apply
        prev->right = ptr;
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("element: %d\n", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    p->left = p1;
    p->right = p2;
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p1->left = p3;
    p1->right = p4;
    insertation(p, 10);
    inOrder(p);
    return 0;
}