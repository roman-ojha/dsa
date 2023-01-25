#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack()
    {
        this->size = 0;
        this->top = -1;
        this->arr = new int[0];
    }

    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[this->size];
    }

    bool is_full()
    {
        return this->top == this->size - 1 ? true : false;
    }

    bool is_empty()
    {
        return this->top == -1 ? true : false;
    }

    void push(int data)
    {
        if (this->is_full())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    int top_of_stack()
    {
        if (this->is_empty())
        {
            cout << "Stack is empty" << endl;
        }
        return this->arr[this->top];
    }

    void pop()
    {
        if (this->is_empty())
        {
            cout << "Stack is empty" << endl;
        }
        this->top--;
    }

    void print()
    {
        int i = this->top;
        while (i >= 0)
        {
            cout << "| " << this->arr[i] << " |" << endl;
            i--;
        }
    }
};

int main()
{
    Stack s(4);
    s.push(10);
    s.push(31);
    s.push(17);
    s.push(24);
    // cout << s.top_of_stack() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.print();
    return 0;
}