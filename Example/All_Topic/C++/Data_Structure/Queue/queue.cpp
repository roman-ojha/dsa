#include <iostream>
using namespace std;

class Queue
{
    int capacity;
    int *arr;
    int f;
    int r;
    int count; // current size of the queue

public:
    Queue(int s)
    {
        capacity = s;
        f = 0;
        r = -1;
        arr = new int[s];
        count = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return (size() == 0);
    }
    bool isFull()
    {
        return (size() == capacity);
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            exit(EXIT_FAILURE);
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        count++;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            exit(EXIT_FAILURE);
        }
        int data = arr[f];
        f = (f + 1) % capacity;
        count--;
        return data;
    }
    int size()
    {
        // size of the queue
        return count;
    }
    int peek()
    {
        // to peek front element
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[f];
    }
};

int main()
{
    Queue q(20);
    q.enqueue(10);
    q.enqueue(3);
    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.peek() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    return 0;
}