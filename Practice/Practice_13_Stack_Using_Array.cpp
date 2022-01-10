#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;

    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size)
        return 1;

    return 0;
}

int push(struct stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow");
        return -1;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s)
{
    int value;
    if (isEmpty(s))
    {
        printf("Stack Underflow");
        return -1;
    }
    value = s->arr[s->top];
    s->top--;
    return value;
}

int peek(struct stack *s, int position)
{
    if (s->top - position + 1 < 0)
    {
        printf("%d position doesn't exist", position);
        return -1;
    }
    else
    {
        return s->arr[s->top - position + 1];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 10);
    push(s, 13);
    push(s, 23);
    push(s, 31);
    push(s, 31);
    push(s, 91);
    // std::cout << "Element: " << pop(s) << std::endl;
    // std::cout << "Element: " << pop(s) << std::endl;
    // std::cout << "Element: " << pop(s) << std::endl;
    // std::cout << "Element: " << pop(s) << std::endl;
    // std::cout << "Element: " << pop(s) << std::endl;
    // std::cout << "Element: " << pop(s) << std::endl;
    // std::cout << "Element: " << pop(s) << std::endl;
    std::cout << "Peeking Element: " << peek(s, 5) << std::endl;
    return 0;
}