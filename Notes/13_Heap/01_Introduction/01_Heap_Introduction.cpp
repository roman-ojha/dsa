/*
# Heap
    ->  Heap is the Almost Complete Binary tree or Complete binary tree
    -> Not necessarily BST
    -> Heap are of two type
        1) MaxHeap
        -> If root > rest of the elements present in its subtree
        -> if this will satisfy to all the node of the tree then it is a MaxHeap
                                6
                               / \
                              5   4
                             / \
                            1   2
        2) MinHeap
            -> If root < rest of the elements present in its subtree
            -> if this will satisfy to all the node of the tree then it is a MinHeap
                                    1
                                   / \
                                  3   2
                                 / \
                                9   8
*/

// Creating Max heap from the given array

#include <iostream>
#include <stdio.h>
using namespace std;

// Heapify method for max heap
void heapify(int A[], int n, int root)
{
    int maxChild = root;
    int leftChild = root * 2;
    int rightChild = root * 2 + 1;

    if (leftChild < n && A[leftChild] > A[rightChild])
    {
        maxChild = leftChild;
    }
    else if (rightChild < n && A[rightChild] > A[leftChild])
    {
        maxChild = rightChild;
    }
    if (A[root] < A[maxChild])
    {
        swap(A[root], A[maxChild]);
        heapify(A, n, maxChild);
    }
}

void createMaxHeap(int A[], int n, int i)
{
    // for (int j = n / 2; j >= 0; j--)
    // {
    //     heapify(A, n, j);
    // }
    if (i < 0)
    {
        return;
    }
    else
    {
        heapify(A, n, i);
        return createMaxHeap(A, n, i - 1);
    }
}

void displayHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int Array[] = {5, 10, 15, 21, 30, 18, 19, 45, 12, 34, 67};
    int n = 11;
    createMaxHeap(Array, n, n / 2);
    displayHeap(Array, n);
    return 0;
}