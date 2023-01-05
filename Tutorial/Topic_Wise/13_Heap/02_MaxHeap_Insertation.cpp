/*
    # Heap
        -> Heap is the Almost Complete Binary tree or Complete binary tree
        => Almost Complete Binary tree
            -> All the level in the tree are completly filled except possible the last level
            -> and in the last level all the keys are align as left as possible
        => Max Heap
            -> for evey node i, the value of node is less then or equal to its parent value
            A[parent[i]] >= A[i] {except root node because root node doesn't have the parent value}
            -> array representataion:
                |70|50|40|45|35|39|16|10|9|
        => Min Heap
            -> for every node i, the value of node is greater then or equal to its parent value
            A[parent[i]] <= A[i] {except root node because root node doesn't have the parent value} {except root node because root node doesn't have the parent value}
            -> array representation:
                |10|15|19|20|30|25|39|23|40|35|
        => Data will insert from the leaf node
        => No. of possible swap = height of the trees (log n)
        => Time complexity of insertation in Max heap is O(log n) 

*/

#include <iostream>
#include <stdio.h>
using namespace std;

void displayHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

void insertation(int A[], int *n, int value)
{
    *n = *n + 1;
    A[*n - 1] = value;
    int i = *n - 1;
    int temp;
    while (i > 0)
    {
        // we have to compare upto root node = 1
        if (A[i] > A[i / 2])
        {
            // if (A[i] child node > A[i / 2] parent node)
            temp = A[i];
            A[i] = A[i / 2];
            A[i / 2] = temp;
            i = i / 2;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int A[20] = {70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5};
    int n = 11; // total number of element
    int value = 51;
    insertation(A, &n, value);
    displayHeap(A, n);
    return 0;
}