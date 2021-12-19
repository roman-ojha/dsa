#include <iostream>
#include <stdio.h>
using namespace std;

// NOTE: there is some problem in this program
void deletion(int A[], int *n)
{
    swap(A[*n - 1], A[0]);
    *n = *n - 1;
    // here swaping means we are deleting the frist element of root element from the tree and deleted element are putting in the swaped element place and decrement the size of array just to store the deleted item as well
    // and after deleting all the element from the heap you will going to get the sorted array
    int i = 1;
    int leftChild = i * 2;
    int rightChild = i * 2 + 1;
    int maxChild;
    while (i < *n)
    {
        if (A[leftChild - 1] > A[rightChild - 1])
        {
            maxChild = leftChild;
        }
        else if (A[leftChild - 1] < A[rightChild - 1])
        {
            maxChild = rightChild;
        }
        if (A[maxChild - 1] > A[i - 1])
        {
            swap(A[maxChild - 1], A[i - 1]);
            i = maxChild;
            leftChild = i * 2;
            rightChild = i * 2 + 1;
        }
        else
        {
            return;
        }
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
    int A[20] = {50, 45, 35, 33, 16, 25, 34, 12, 10};
    int n = 9;
    deletion(A, &n);
    deletion(A, &n);
    displayHeap(A, n);
    return 0;
}