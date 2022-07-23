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

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
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
    postOrder(p);
    return 0;
}