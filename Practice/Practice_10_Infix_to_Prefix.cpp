#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        return -1;
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

int Presedence(char c)
{
    if (c == '(')
    {
        return 0;
    }
    if (c == '*' || c == '/' || c == '%')
    {
        return 2;
    }
    if (c == '+' || c == '-')
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

char *reverseExpression(char *revInfix, int expSize, char infix[])
{
    int j = 0;
    for (int i = expSize - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
        {
            revInfix[j] = ')';
        }
        else if (infix[i] == ')')
        {
            revInfix[j] = '(';
        }
        else
        {
            revInfix[j] = infix[i];
        }
        j++;
    }
    revInfix[j] = '\0';
    return revInfix;
}

void infixToPrefix(char infix[])
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    int expSize = 0;
    while (infix[expSize] != '\0')
    {
        expSize++;
    }
    s->size = expSize;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *prefix = (char *)malloc(s->size * sizeof(char));
    char *revInfix = (char *)malloc(s->size * sizeof(char));
    char *rev = reverseExpression(revInfix, expSize, infix);
    // int i = 0;
    // int j = 0;
    // int x;
    // while (rev[i] != '\0')
    // {
    //     if (!isOperator(rev[i]) && !isParenthesis(rev[i]))
    //     {
    //         prefix[j] = rev[i];
    //         j++;
    //     }
    //     else if (isOperator(rev[i]))
    //     {

    //         while (Presedence(s->top) >= Presedence(rev[i]))
    //         {
    //             prefix[j] = pop(s);
    //             j++;
    //         }
    //         push(s, rev[i]);
    //     }
    //     else
    //     {
    //         if (isParenthesis(rev[i]) == 2)
    //         {
    //             push(s, rev[i]);
    //         }
    //         else
    //         {
    //             while ((x = pop(s)) != '(')
    //             {
    //                 prefix[j] = x;
    //                 j++;
    //             }
    //         }
    //     }
    //     i++;
    // }

    int i = 0;
    int j = 0;
    char x;
    while (rev[i] != '\0')
    {
        if (isalnum(rev[i]))
        {
            prefix[j] = rev[i];
            j++;
            // printf("%c", rev[i]);
        }
        else if (rev[i] == '(')
        {
            push(s, rev[i]);
        }
        else if (rev[i] == ')')
        {
            while ((x = pop(s)) != '(')
            {
                prefix[j] = x;
                j++;
                // printf("%c", x);
            }
        }
        else
        {
            while (Presedence(s->top) >= Presedence(rev[i]))
            {
                prefix[j] = pop(s);
                j++;
                // printf("%c", pop(s));
            }
            push(s, rev[i]);
        }
        i++;
    }
    while (!isEmpty(s))
    {
        prefix[j] = pop(s);
        j++;
    }
    prefix[j] = '\0';
    cout << prefix << endl;
    // cout << rev << endl;
}

int main()
{
    char exp[50];
    printf("Enter The expression: ");
    gets(exp);
    infixToPrefix(exp);
    return 0;
}