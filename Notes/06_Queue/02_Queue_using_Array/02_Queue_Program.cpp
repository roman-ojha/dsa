#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    int size;
    int front;
    int rare;
    T *arr;

public:
    Queue() : size(0), front(0), rare(0), arr(nullptr) {}
    Queue(int size) : size(0)
    {
        this->arr = new int[size];
        this->front = -1;
        this->rare = -1;
    }
    ~Queue()
    {
        delete[] this->arr;
    }

    bool empty()
    {
        return this->front == -1 || this->front > this->rare ? true : false;
    }

    bool full()
    {
        return this->rare == this->size - 1 ? true : false;
    }

    void enqueue(int val)
    {
        if (this->front == -1 && this->rare == -1)
        {
            this->front = 0;
            this->rare = 0;
            this->arr[this->rare] = val;
            return;
        }
        else if (this->full())
        {
            cout << "Queue is full" << endl;
            return;
        }
        this->rare++;
        this->arr[this->rare] = val;
    }

    void top()
    {
        return this->arr[this->front];
    }

    void back()
    {
        return this->arr[this->rare];
    }

    void dequeue()
    {
        if (this->empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        this->front++;
    }

    int *data()
    {
        // return underlying array
        return this->arr;
    }

    int queue_rare()
    {
        return this->rare;
    }

    int queue_front()
    {
        return this->front;
    }
};

// print queue
void print_queue(int *arr, int front, int rare)
{
    for (int i = front; i <= rare; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue<int> q(50);
    q.enqueue(10);
    q.enqueue(13);
    q.enqueue(41);
    q.enqueue(38);

    int *arr = q.data();
    int front = q.queue_front();
    int rare = q.queue_rare();
    print_queue(arr, front, rare);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    arr = q.data();
    front = q.queue_front();
    rare = q.queue_rare();
    print_queue(arr, front, rare);

    return 0;
}