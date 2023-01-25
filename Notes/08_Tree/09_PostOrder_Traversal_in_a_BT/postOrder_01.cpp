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
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("element: %d\n", root->data);
    }
}

int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    p->left = p1;
    p->right = p2;
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    p1->left = p3;
    p1->right = p4;
    /*
            4
           / \
          1   6
         / \
        5   2
    */
    postOrder(p);
    return 0;
}