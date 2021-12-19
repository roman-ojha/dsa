#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct queue
{
    int size;
    int front;
    int rare;
    int *arr;
};

void traversal(struct queue *ptr)
{
    for (int i = ptr->front; i <= ptr->rare; i++)
    {
        printf("Element %d is: %d \n", i, ptr->arr[i]);
    }
}

int enqueue(struct queue *ptr, int value)
{
    if (ptr->rare == ptr->size - 1)
    {
        printf("Queue is full");
        return 0;
    }
    ptr->rare++;
    ptr->arr[ptr->rare] = value;
    return 1;
}

int main()
{
    struct queue *p;
    p = (struct queue *)malloc(sizeof(struct queue));
    p->size = 10;
    p->front = -1;
    p->rare = -1;
    p->arr = (int *)malloc(p->size * sizeof(int *));
    enqueue(p, 8);
    p->front = 0;
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    enqueue(p, 8);
    traversal(p);
    return 0;
}