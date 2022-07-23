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

int isBST(struct Node *root)
{
    // checking using inorder method
    static struct Node *prev;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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
    if (isBST(p))
    {
        cout << "The given tree is BST" << endl;
    }
    else
    {
        cout << "The given tree is not BST" << endl;
    }
    return 0;
}