#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr)
{
    if (ptr->r == (ptr->size - 1))
    {
        return 1;
    }
    return 0;
}

int traversal(struct queue *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        int count = 0;
        for (int i = ptr->f + 1; i <= ptr->r; i++)
        {
            printf("Element %d is: %d \n", count, ptr->arr[i]);
            count++;
        }
    }
    return 1;
}

void enqueue(struct queue *ptr, int value)
{

    if (isFull(ptr))
    {
        cout << "Queue is full" << endl;
    }
    else if (ptr->r == ptr->f)
    {
        ptr->f = 0;
        ptr->r = 0;
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = value;
    }
}

void dqueue(struct queue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Queue is empty" << endl;
        ptr->f = -1;
        ptr->r = -1;
    }
    else
    {
        ptr->f++;
    }
}

int main()
{
    struct queue *p;
    p = (struct queue *)malloc(sizeof(struct queue));
    p->size = 10;
    p->f = -1;
    p->r = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));
    enqueue(p, 10);
    enqueue(p, 9);
    enqueue(p, 8);
    enqueue(p, 7);
    enqueue(p, 6);
    enqueue(p, 5);
    enqueue(p, 4);
    enqueue(p, 3);
    enqueue(p, 2);
    enqueue(p, 1);
    enqueue(p, 0);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    enqueue(p, 0);
    enqueue(p, 0);
    enqueue(p, 0);
    enqueue(p, 0);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    dqueue(p);
    traversal(p);
    return 0;
}