#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *searching(struct Node *root, int value)
{
    if (root != NULL)
    {
        if (root->data > value)
        {
            return searching(root->left, value);
        }
        else if (root->data < value)
        {
            return searching(root->right, value);
        }
        else
        {
            return root;
        }
    }
    else
    {

        return NULL;
    }
}

int main()
{
    struct Node *p, *p1, *p2, *p3, *p4, *p5, *p6;
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
    int element = 9;
    struct Node *n = searching(p, element);
    if (n == NULL)
    {
        cout << "Element " << element << " not found in the BST" << endl;
    }
    else
    {
        cout << "Element " << element << " found in the BST" << endl;
    }
    return 0;
}