/*
    -> https://leetcode.com/problems/min-stack/description/
    *) Min Stack
        Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

        Implement the MinStack class:

        MinStack() initializes the stack object.
        void push(int val) pushes the element val onto the stack.
        void pop() removes the element on the top of the stack.
        int top() gets the top element of the stack.
        int getMin() retrieves the minimum element in the stack.
        You must implement a solution with O(1) time complexity for each function.

        Example 1:
        Input
        ["MinStack","push","push","push","getMin","pop","top","getMin"]
        [[],[-2],[0],[-3],[],[],[],[]]

        Output
        [null,null,null,null,-3,null,0,-2]

        Explanation
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin(); // return -3
        minStack.pop();
        minStack.top();    // return 0
        minStack.getMin(); // return -2

        Constraints:
        -231 <= val <= 231 - 1
        Methods pop, top and getMin operations will always be called on non-empty stacks.
        At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    vector<int> *arr;
    stack<int> *minSt;

public:
    MinStack()
    {
        this->arr = new vector<int>;
        this->minSt = new stack<int>;
    }

    void push(int val)
    {
        int min = val;
        if (!this->minSt->empty() && min > this->minSt->top())
        {
            min = this->minSt->top();
        }
        this->arr->push_back(val);
        this->minSt->push(min);
    }

    void pop()
    {
        this->arr->pop_back();
        this->minSt->pop();
    }

    int top()
    {
        return this->arr->back();
    }

    int getMin()
    {
        return this->minSt->top();
    }
};

int main()
{

    return 0;
}