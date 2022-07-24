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
};

int main()
{
    int size = 100;
    Stack s(size);
    s.arr = new int[size];
    return 0;
}