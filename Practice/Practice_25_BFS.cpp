#include <iostream>
#include <stdlib.h>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}};

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct Queue *q)
{
    int value = -1;
    if (isEmpty(q))
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        q->f++;
        value = q->arr[q->f];
    }
    return value;
}

void BFS(int i)
{
    struct Queue q;
    q.size = 400;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    cout << i << " ";
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (A[node][j] == 1 && !visited[j])
            {
                cout << j << " ";
                enqueue(&q, j);
                visited[j] = 1;
            }
        }
    }
}

int main()
{
    BFS(0);
    return 0;
}