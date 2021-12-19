#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isParenthesis(char op)
{
    if (op == '(')
    {
        return 1;
    }
    else if (op == ')')
    {
        return 2;
    }
    return 0;
}

void push(struct stack *ptr, char par)
{
    if (isFull(ptr))
    {
        cout << "Stack is full Sorry!!";
        exit(0);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = par;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Parenthesis not Match opps!!";
        exit(0);
    }
    else
    {
        ptr->top--;
    }
}

void prenthesisMatch(string exp)
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 30;
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top = -1;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isParenthesis(exp[i]) == 1)
        {
            // opening
            push(s, exp[i]);
        }
        else if (isParenthesis(exp[i]) == 2)
        {
            //closing
            pop(s);
        }
        i++;
    }
    if (isEmpty(s))
    {
        cout << "Parenthesis Match :)" << endl;
    }
    else
    {
        cout << "Parenthesis not Match opps!!" << endl;
    }
};

int main()
{

    string e = "(7*8)-3(7)())";
    prenthesisMatch(e);
    return 0;
}