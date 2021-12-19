#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        value = ptr->arr[ptr->top];
        ptr->top--;
    }
    return value;
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 5);
    push(s, 4);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    cout << "Element: " << pop(s) << endl;
    return 0;
}