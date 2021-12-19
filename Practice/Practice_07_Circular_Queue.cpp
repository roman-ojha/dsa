#include <iostream>
#include <stdlib.h>
using namespace std;

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "circularQueue is full" << endl;
    }
    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = value;
    }
}

int dequeue(struct circularQueue *ptr)
{
    int temp;
    if (isEmpty(ptr))
    {
        cout << "circularQueue is empty" << endl;
        return 0;
    }
    else
    {

        ptr->f = (ptr->f + 1) % ptr->size;
        temp = ptr->arr[ptr->f];
    }
    return temp;
}

int main()
{
    struct circularQueue p;
    p.size = 10;
    p.arr = (int *)malloc(p.size * sizeof(int));
    p.f = 0;
    p.r = 0;
    enqueue(&p, 4);
    enqueue(&p, 5);
    enqueue(&p, 6);
    enqueue(&p, 7);
    enqueue(&p, 8);
    enqueue(&p, 9);
    enqueue(&p, 10);

    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    return 0;
}