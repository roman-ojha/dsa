#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct queue *front, *rare;

struct queue
{
    int data;
    struct queue *next;
};

void enqueue(int value)
{

    struct queue *ptr = (struct queue *)malloc(sizeof(struct queue));
    ptr->data = value;
    ptr->next = NULL;
    if (rare == NULL)
    {
        rare = ptr;
        front = ptr;
    }
    else
    {
        rare->next = ptr;
        rare = ptr;
    }
}

int dequeue()
{
    int value = 0;
    struct queue *ptr = front;
    if (front == NULL)
    {
        cout << "queue is empty" << endl;
    }
    else if (front == rare)
    {
        value = front->data;
        front = NULL;
        rare = NULL;
        free(ptr);
    }
    else
    {
        value = front->data;
        front = front->next;
        free(ptr);
    }
    return value;
}

int main()
{
    front = NULL;
    rare = NULL;
    enqueue(10);
    enqueue(11);
    enqueue(17);
    enqueue(14);
    enqueue(12);
    cout << "value: " << dequeue() << endl;
    cout << "value: " << dequeue() << endl;
    cout << "value: " << dequeue() << endl;
    cout << "value: " << dequeue() << endl;
    cout << "value: " << dequeue() << endl;
    cout << "value: " << dequeue() << endl;
    return 0;
}