#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} * p, *p1, *p2, *p3, *p4, *p5, *p6;

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertation(struct Node *root, struct Node *prev, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        if (root->data < prev->data)
        {
            prev->left = root;
        }
        else
        {
            prev->right = root;
        }
        return;
    }
    else if (root->data > data)
    {
        prev = root;
        insertation(root->left, prev, data);
    }
    else if (root->data < data)
    {
        prev = root;
        insertation(root->right, prev, data);
    }
}

void insertionAnother(struct Node *root, int data)
{
    struct Node *n = createNode(data);
    while (root != NULL)
    {

        if (root->left == NULL && root->data > data)
        {
            root->left = n;
            break;
        }
        else if (root->right == NULL && root->data < data)
        {
            root->right = n;
            break;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else if (root->data < data)
        {
            root = root->right;
        }
        else
        {
            printf("given data is already exist in the tree");
            break;
        }
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    p = createNode(10);
    p1 = createNode(8);
    p2 = createNode(12);
    p->left = p1;
    p->right = p2;
    p3 = createNode(6);
    p4 = createNode(9);
    p1->left = p3;
    p1->right = p4;
    p5 = createNode(11);
    p6 = createNode(14);
    p2->left = p5;
    p2->right = p6;
    insertation(p, NULL, 13);
    inOrder(p);
    return 0;
}