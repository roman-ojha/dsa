#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Queue is overflow");
    }
    ptr->r++;
    ptr->arr[ptr->r] = data;
}

int dequeue(struct Queue *ptr)
{
    int data;
    if (isEmpty(ptr))
    {
        printf("Queue is underflow");
        return -1;
    }
    ptr->f++;
    data = ptr->arr[ptr->f];
    return data;
}

void traversal(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("queue is underflow");
    }
    for (int i = ptr->f + 1; i <= ptr->r; i++)
    {
        printf("%d ->", ptr->arr[i]);
    }
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 10);
    q->f = 0;
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 15);
    enqueue(q, 16);
    enqueue(q, 17);
    enqueue(q, 18);
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    std::cout << "Dequeuing Element: " << dequeue(q) << std::endl;
    traversal(q);
    return 0;
}