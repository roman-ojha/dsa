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

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("element: %d\n", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    //NOTE:  to check whether it is BST or not, we can create a inorder traversal using that we can creat an ascending order and after that we can compare, if previous data is lesser then current data then we can say that it is a bst

    static struct node *prev = NULL;
    // firstly prev will point to the root
    // here we are checking using inorder
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
            // is not BST
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
            // is not BST
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
        // is BST
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
    /*
            5
           / \
          3   6
         / \
        1   4
    */
    inOrder(p);
    printf("%d", isBST(p));
    return 0;
}