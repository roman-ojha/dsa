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
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node *inOrderPredecessor(struct node *root)
{
    // inOrder Predecessor is the Left subtree Right most child
    // so we have to return that value
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // after recursive call we will come to this position where
        // after replacing all the node we will come to the leaf node now that node value will going to be the 'value' that we want to delete
        free(root);
        return NULL;
    }
    // Search for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // Deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        // here we have to get the inorder predecessor the the node
        root->data = iPre->data;
        // replacing inorder predecessor value with root
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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
    inOrder(p);
    deleteNode(p, 6);
    printf("\n");
    inOrder(p);
    return 0;
}