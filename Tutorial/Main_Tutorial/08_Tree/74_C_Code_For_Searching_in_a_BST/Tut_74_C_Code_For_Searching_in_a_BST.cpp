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
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
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
    struct node *n = search(p, 4);
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