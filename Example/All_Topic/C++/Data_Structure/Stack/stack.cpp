#include <iostream>
#include <tuple>
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
    // tuple<bool, int> pop()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Stack is empty" << endl;
    //         return {false, 0};
    //     }
    //     top--;
    //     return {true, arr[top + 1]};
    // }
    // tuple<bool, int> topOfStack()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Stack is empty" << endl;
    //         return {false, 0};
    //     }
    //     return {true, arr[top]};
    // }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        top--;
        return arr[top + 1];
    }
    int topOfStack()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return arr[top];
    }
};

int main()
{
    int size = 100;
    Stack s(size);
    s.arr = new int[size];
    // auto [isPop1, Pop1] = s.pop();
    s.push(10);
    s.push(15);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.topOfStack() << endl;
    return 0;
}