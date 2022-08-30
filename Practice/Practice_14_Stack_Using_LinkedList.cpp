#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *ptr = NULL;

int isEmpty()
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        delete (n);
        return 1;
    }
    delete (n);
    return 0;
}

void push(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = ptr;
    ptr = n;
}

int pop()
{
    int data;
    if (isEmpty())
    {
        printf("Stack is underflow");
        return -1;
    }
    data = ptr->data;
    struct Node *temp = ptr;
    ptr = ptr->next;
    delete (temp);
    return data;
}

int peek(int position)
{
    struct Node *temp = ptr;
    // if (isEmpty())
    // {
    //     printf("Stack is empty");
    //     return -1;
    // }
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Position doesn't exist");
            return -1;
        }
    }
    return temp->data;
}

int main()
{
    push(10);
    push(11);
    push(12);
    push(13);
    push(14);
    // cout << "Element: " << pop() << endl;
    // cout << "Element: " << pop() << endl;
    // cout << "Element: " << pop() << endl;
    // cout << "Element: " << pop() << endl;
    // cout << "Element: " << pop() << endl;
    // cout << "Element: " << pop() << endl;
    push(15);
    push(16);
    push(17);
    push(18);
    cout << "Element: " << pop() << endl;
    cout << "Peeking Element: " << peek(9) << endl;
    return 0;
}