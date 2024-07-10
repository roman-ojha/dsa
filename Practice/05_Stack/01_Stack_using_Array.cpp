#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int top;

public:
    Stack(int size)
    {
        this->arr = new int[0];
        this->size = size;
        this->top = -1;
    }

    bool isFull()
    {
        if (this->top + 1 == this->size)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (this->top == -1)
            return true;
        return false;
    }

    void travel()
    {
        cout << endl;
        for (int i = this->top; i >= 0; i--)
        {
            cout << "| " << this->arr[i] << " |" << endl;
        }
    }

    void push(int element)
    {
        if (this->isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = element;
    }

    int pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        return this->arr[this->top--];
    }
};

int main()
{
    Stack s(100);
    s.push(10);
    s.push(12);
    s.push(143);
    s.push(143);
    s.push(43);
    s.push(14);
    s.travel();
    cout << s.pop() << ",";
    cout << s.pop() << ",";
    cout << s.pop() << ",";
    s.push(14);
    s.travel();
    return 0;
}