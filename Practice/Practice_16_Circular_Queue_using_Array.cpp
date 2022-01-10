#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is overflow");
    }
    else
    {
        if (q->f == -1)
        {
            q->f = 0;
        }
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
    }
}

int dequeue(struct Queue *q)
{
    int data;
    if (isEmpty(q))
    {
        printf("Queue is UnderFlow");
        return -1;
    }
    q->f = (q->f + 1) % q->size;
    data = q->arr[q->f];
    return data;
}

int main()
{
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 10);
    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 14);
    enqueue(&q, 14);
    enqueue(&q, 14);
    enqueue(&q, 14);
    enqueue(&q, 14);
    enqueue(&q, 14);
    enqueue(&q, 14);
    // cout << "Dequeue Element: " << dequeue(&q) << endl;
    // cout << "Dequeue Element: " << dequeue(&q) << endl;
    // cout << "Dequeue Element: " << dequeue(&q) << endl;
    // cout << "Dequeue Element: " << dequeue(&q) << endl;
    // cout << "Dequeue Element: " << dequeue(&q) << endl;
    // cout << "Dequeue Element: " << dequeue(&q) << endl;
    return 0;
}