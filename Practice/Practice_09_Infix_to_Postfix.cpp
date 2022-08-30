#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
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
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    char temp;
    if (isEmpty(ptr))
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        temp = ptr->arr[ptr->top];
        ptr->top--;
    }
    return temp;
}

int isOperator(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-' || c == '%')
    {
        return 1;
    }
    return 0;
}

int Associativity(char c)
{
    if (c == '*' || c == '/' || c == '%')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

int isParenthesis(char c)
{
    if (c == '(')
    {
        return 2;
    }
    else if (c == ')')
    {
        return 1;
    }
    return 0;
}

void infixToPostfix(char exp[])
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 50;
    s->arr = (char *)malloc(s->size * sizeof(struct stack));
    int i = 0;
    int j = 0;
    char postfix[50];
    while (exp[i] != '\0')
    {
        if (isOperator(exp[i]))
        {
            if (Associativity(exp[i]) > Associativity(s->top))
            {
                push(s, exp[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
        else if (isParenthesis(exp[i]) == 0)
        {

            if (isParenthesis(exp[i]) == 2)
            {
                // opening
                push(s, exp[i]);
                i++;
            }
            else
            {
                // closing
                while (s->top != '(')
                {
                    postfix[j] = pop(s);
                    j++;
                }
                pop(s);
            }
        }
        else
        {
            postfix[j] = exp[i];
            j++;
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    printf("%s", postfix);
}

int main()
{
    char exp[50];
    printf("Enter The expression: ");
    gets(exp);
    infixToPostfix(exp);
    return 0;
}