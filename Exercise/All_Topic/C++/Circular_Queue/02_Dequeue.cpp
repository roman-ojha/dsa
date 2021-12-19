#include <iostream>
#include <stdio.h>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *ptr)
{
    if (ptr->f == (ptr->r + 1) % ptr->size)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *ptr)
{
    if (ptr->f == -1 && ptr->r == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Queue is full" << endl;
    }
    else if (ptr->f == -1 && ptr->r == -1)
    {
        ptr->f = 0;
        ptr->r = 0;
        ptr->arr[ptr->r] = value;
    }
    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = value;
    }
}

int dequeue(struct queue *ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        cout << "Queue is Empty" << endl;
    }
    else if (ptr->f == ptr->r)
    {
        value = ptr->arr[ptr->f];
        ptr->f = -1;
        ptr->r = -1;
    }
    else
    {
        value = ptr->arr[ptr->f];
        ptr->f = (ptr->f + 1) % (ptr->size);
    }
    return value;
}

int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 10);
    enqueue(q, 9);
    enqueue(q, 8);
    enqueue(q, 7);
    enqueue(q, 6);
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    cout << "Dqueue value is: " << dequeue(q) << endl;
    return 0;
}