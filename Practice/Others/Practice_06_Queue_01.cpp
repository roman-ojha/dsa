#include <iostream>
using namespace std;
#include <stdlib.h>

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

void enqueue(struct queue *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = value;
    }
}

int dequeue(struct queue *ptr)
{
    int temp;
    if (isEmpty(ptr))
    {
        cout << "Queue is empty";
        return 0;
    }
    temp = ptr->arr[ptr->f + 1];
    ptr->f++;
    return temp;
}

int peek(struct queue *ptr, int pos)
{
    int p = ptr->f;
    int temp = 1;
    while (temp <= pos)
    {
        if (p == ptr->r)
        {
            cout << pos << " don't exits in queue" << endl;
        }
        else if (temp == pos)
        {
            return ptr->arr[p];
        }
        p++;
    }
    return 0;
}

void traversal(struct queue *ptr)
{
    int temp = ptr->f + 1;
    while (temp <= ptr->r)
    {
        cout << ptr->arr[temp] << " ";
        temp++;
    }
}

int firstVal(struct queue *ptr)
{
    return ptr->arr[ptr->f + 1];
}
int lastVal(struct queue *ptr)
{
    return ptr->arr[ptr->r];
}

int main()
{
    struct queue p;
    p.size = 10;
    p.arr = (int *)malloc(p.size * sizeof(int));
    p.f = -1;
    p.r = -1;
    enqueue(&p, 4);
    enqueue(&p, 5);
    enqueue(&p, 6);
    enqueue(&p, 7);
    enqueue(&p, 8);
    enqueue(&p, 9);
    enqueue(&p, 10);

    traversal(&p);
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    cout << dequeue(&p) << endl;
    return 0;
}