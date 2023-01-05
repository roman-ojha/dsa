#include <iostream>
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
    if (ptr->top == (ptr->size) - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow!!!" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "\nStack Underflow!!!" << endl;
    }
    else
    {
        ptr->top--;
    }
}

void peek(struct stack *ptr, int position)
{
    for (int i = ptr->top; i >= position; i--)
    {
        cout << "The value at " << position << " is: " << ptr->arr[i] << endl;
    }
}

void traversal(struct stack *ptr)
{
    cout << "The given element are: ";
    for (int i = 0; i <= ptr->top; i++)
    {
        cout << ptr->arr[i] << " ";
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // pop(&s);
    push(s, 10);
    push(s, 10);
    push(s, 16);
    push(s, 17);
    push(s, 14);
    push(s, 14);
    traversal(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    cout << endl;
    traversal(s);
    peek(s, 3);
    return 0;
}