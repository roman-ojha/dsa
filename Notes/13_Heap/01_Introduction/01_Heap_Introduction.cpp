/*
# Heap
    -> Heap is the Almost Complete Binary tree or Complete binary tree
    -> Not necessarily BST
    *) Binary Heap:
        -> https://www.geeksforgeeks.org/binary-heap/
        -> Binary Heap follows the property of BT
        -> Property:
            -> It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.
            -> A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.
        -> This property of Binary Heap makes them suitable to be stored in an array.
    -> Binary Heap are of two type
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

    -> How is Binary Heap represented?
            A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.

            The root element will be at Arr[0].
            Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
            Arr[(i-1)/2]	Returns the parent node
            Arr[(2*i)+1]	Returns the left child node
            Arr[(2*i)+2]	Returns the right child node
    -> The traversal method use to achieve Array representation is Level Order
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