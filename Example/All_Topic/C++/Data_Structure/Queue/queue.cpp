#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int *arr;
    int f;
    int r;
    bool isEmpty()
    {
        if (f == r)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (((f + 1) % size) == (r % size))
        {
            return true;
        }
        return false;
    }
    void enqueue(int data)
    {
        if (f == -1 && r == -1)
        {
            f++;
            r++;
            arr[r] = data;
            return;
        }
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        r = (r + 1) % size;
        arr[r] = data;
    }
};

int main()
{

    return 0;
}