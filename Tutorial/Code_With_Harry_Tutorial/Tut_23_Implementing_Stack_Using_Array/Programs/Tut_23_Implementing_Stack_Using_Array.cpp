#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*

-> stack is the collection of element in FILO manner
->in a stack we use "Top" which point or represent the element of the stack
-> if the stack have 2 element then the value of "Top" will be 1
-> if the stack have 1 element then the value of the "Top" will be 0
-> if the stack have 0 element them the value of the "top" will be -1
-> Top could be pointer But also could be storeing value of the index of stored element in stack
*/

/*
Implementing stack using Arrays :
-> Fixed size array creation
-> Top Element which store the top element index
*/

/*
better way to use array for stack
    | | -> 3 index
    | | -> 2 index
    | | -> 1 index
    |_| -> 0 index

we use like this because for most of the insertion time complexity of this process will be O(1)
*/

/*
Syntax:
    struct stack
    {
        int size;
        int top; // it could be pointer
        int *arr; // because we are trying to make array in heap using malloc or new operator
    }
*/

int main()
{
    return 0;
}