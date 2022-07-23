#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct stack
{
    int data;
    struct stack *next;
};

int isEmpty(struct stack *TOS)
{
    if (TOS == NULL)
    {
        return 1;
    }
    return 0;
}

struct stack *push(struct stack *TOS, int value)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = value;
    ptr->next = NULL;
    if (isEmpty(TOS))
    {
        TOS = ptr;
        cout << "is empty" << endl;
    }
    else
    {
        ptr->next = TOS;
        TOS = ptr;
        cout << "is not empty" << endl;
    }
    return TOS;
}

struct stack *pop(struct stack *TOS)
{
    int value = 0;
    struct stack *ptr;
    if (isEmpty(TOS))
    {
        cout << "Stack underflow" << endl;
    }
    else if (TOS->next == NULL)
    {
        ptr = TOS;
        value = ptr->data;
        TOS = NULL;
        // cout << ptr->data;
        free(ptr);
    }
    else
    {
        ptr = TOS;
        value = ptr->data;
        TOS = TOS->next;
        free(ptr);
    }
    cout << "value: " << value << endl;
    return TOS;
}

int main()
{
    struct stack *TOS;
    TOS = NULL;
    TOS = push(TOS, 4);
    TOS = push(TOS, 6);
    TOS = pop(TOS);
    TOS = pop(TOS);
    TOS = pop(TOS);
    return 0;
}