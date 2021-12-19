#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *ptr, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = ptr;
    return temp;
}

struct Node *pop(struct Node *ptr, int *returnData)
{
    struct Node *p;
    if (isEmpty(ptr))
    {
        printf("Stack is underflow!!!");
        ptr = NULL;
        return ptr;
    }
    *returnData = ptr->data;
    p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
}

int main()
{
    struct Node *top, *second, *third, *fourth;
    int top = -1;
    top = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    top->data = 10;
    top->next = second;
    second->data = 15;
    second->next = third;
    third->data = 20;
    third->next = fourth;
    fourth->data = 25;
    fourth->next = NULL;
    // isEmpty(top);
    top = push(top, 5);
    int returnData;
    top = pop(top, &returnData);
    cout << "Element: " << returnData << endl;
    top = pop(top, &returnData);
    cout << "Element: " << returnData << endl;
    top = pop(top, &returnData);
    cout << "Element: " << returnData << endl;
    top = pop(top, &returnData);
    cout << "Element: " << returnData << endl;
    top = pop(top, &returnData);
    cout << "Element: " << returnData << endl;
    top = pop(top, &returnData);
    cout << "Element: " << returnData << endl;
    return 0;
}