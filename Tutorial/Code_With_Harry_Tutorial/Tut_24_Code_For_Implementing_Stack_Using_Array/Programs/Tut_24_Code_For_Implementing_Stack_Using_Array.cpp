#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// we are checking does stack is empty of not
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// we are checking is stack is full of not
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s;
    struct stack st;
    s = &st;
    s->size = 80;
    s->top = -1; // -1 denote that you stack is empty
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an element manually
    // s->arr[0] = 7;
    // s->top++;

    // Check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }
    return 0;
}