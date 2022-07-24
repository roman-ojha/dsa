#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int *arr;
    int top;
    Stack(int s)
    {
        size = s;
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
        return arr[top + 1];
    }
    int topOfStack()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        return arr[top];
    }
};

int main()
{
    int size = 100;
    Stack s(size);
    s.arr = new int[size];
    return 0;
}