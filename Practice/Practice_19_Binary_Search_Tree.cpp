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

struct Node *createNode(int value)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *previous = NULL;
int isBST(struct Node *root)
{
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (previous != NULL && previous->data >= root->data)
        {
            return 0;
        }
        previous = root;
        return isBST(root->right);
    }
    return 1;
}

void inOrder(struct Node *root)
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
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(6);
    p->left = p1;
    p->right = p2;
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(3);
    p1->left = p3;
    p1->right = p4;
    struct Node *p5 = createNode(5);
    struct Node *p6 = createNode(7);
    p2->left = p5;
    p2->right = p6;
    inOrder(p);
    printf("%d", isBST(p));
    return 0;
}
