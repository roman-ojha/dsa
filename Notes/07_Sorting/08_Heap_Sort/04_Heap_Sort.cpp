/*
    # Sorting Heap process using deletion concept:
        1) Build a MaxHeap.
        2) Delete 0th index from MaxHeap.
        3) Deleted node will go the the index which index value we are placing into the 0th index
        4) Heapify the Remaining MaxHeap
        5) Repeat 2, 3, 4 steps
        6) After all the deleted data that we delete will be in sorted order.
    => Time Complexity
        => in creation O(nlog n)
        => in deletion O(nlog n)
        => Total = O(nlog n)+O(nlog n) => O(2nlog n) => O(nlog n)

    => we can decrease the time Complexity to O(n) by Heapify method
    # Heapify method
        => Time Complexity for creation of MaxHeap using Heapify method is O(n)
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

void heapify(int A[], int n, int i)
{
    int largest = i;
    // i is the starting point to make a max heap which is not the leaf node
    // and largest is the node from which we will make the max heap
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    int temp;

    if (l < n && A[l] > A[largest])
    {
        // now we will consider that left child is the largest
        largest = l;
    }
    if (r < n && A[r] > A[largest])
    {
        // now we will consider that right child is the largest
        largest = r;
    }
    if (largest != i)
    {
        // it means largest had be updated it means we have to swap
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        // again we have to make max heap for largest so we have to use recursion
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    int temp;
    // we will start the Sorting from the non leaf node
    // Building the MaxHeap
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(A, n, i);
    }
    // Deleting the node from the root node
    for (int i = n - 1; i >= 0; i--)
    {
        // we have to reduce the size of array after storing the data in 'i' that's why we have to start the loop from 'n-1'
        // Swap the root node with the last leaf node to say that the root node is now deleted
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        // now after swap we will check is tree again stisfy the MaxHeap property
        // for that we have to use heapify method again
        heapify(A, i, 0);
        // in i we have to pass 0
        // here we will only going to call the heapify method for the root node
    }
}

int main()
{
    int A[7] = {15, 5, 20, 1, 17, 10, 30};
    int n = 7;
    heapSort(A, n);
    displayHeap(A, n);
    return 0;
}