#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *s, char parenthesis)
{
    if (isFull(s))
    {
        printf("Stack overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = parenthesis;
    }
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        return 0;
    }
    s->top--;
    return 1;
}

int parenthesisMatching(char exp[])
{
    struct Stack s;
    s.top = -1;
    s.size = 30;
    s.arr = (char *)malloc(s.size * (sizeof(char)));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            int res = pop(&s);
            if (!res)
            {
                return 0;
            }
        }
    }
    if (isEmpty(&s))
    {
        return 1;
    }
    return 0;
}

int main()
{

    char exp[] = "7-(8(3*9)+11+12)-8";
    if (parenthesisMatching(exp))
    {
        printf("This is balance parenthesis");
    }
    else
    {
        printf("This is not balance parenthesis");
    }
    return 0;
}