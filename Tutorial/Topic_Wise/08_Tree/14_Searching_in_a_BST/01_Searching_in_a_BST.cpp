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

struct node *search(struct node *root, int value)
{
    // in best case time complexcity is O(logn)
    // in worst case O(n)
    if (root != NULL)
    {
        if (root->data > value)
        {
            return search(root->left, value);
        }
        else if (root->data < value)
        {
            return search(root->right, value);
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

void inOrder(struct node *root)
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
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    // inOrder(p);
    struct node *n = search(p, 1);
    if (n != NULL)
    {

        cout << "element found: " << n->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}