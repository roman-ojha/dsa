#include <iostream>
#include <stdlib.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *array;
};

void insertion(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << "Element " << i + 1 << " : ";
        cin >> s->array[i];
    }
}

void displayStack(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << "Element " << i + 1 << " : " << s->array[i] << endl;
    }
}

void isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        cout << "The Stack is emply";
    }
}

void isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        cout << "The Stack is full";
    }
}

void push(struct Stack *s, int number)
{
    s->array[s->top + 1] = number;
    s->top++;
}

int main()
{
    struct Stack *s;
    struct Stack st;
    s = &st;
    s->size = 10;
    cout << "Enter the size of stack that you want to create:";
    cin >> s->top;
    s->top--;
    cout << "Enter the element to insert in the stack:" << endl;
    s->array = (int *)malloc(s->size * sizeof(int));
    insertion(s);
    cout << "The given element are:" << endl;
    displayStack(s);
    isEmpty(s);
    isFull(s);
    cout << "Enter the number that you want to push in the stack";
    int number;
    cin >> number;
    push(s, number);
    displayStack(s);
    return 0;
}