#include <iostream>
#include <stdio.h>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    { // For number of passes
        for (int j = 0; j < n - 1 - i; j++)
        {
            // for every passes
            if (A[j] > A[j + 1])
            {
                temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
            }
        }
    }
}

// I am just making this function for understanding
void adaptiveBubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    { // For number of passes
        printf("Hello\n");
        for (int j = 0; j < n - 1 - i; j++)
        {
            isSorted = 1;
            // for every passes
            if (A[j] > A[j + 1])
            {
                // if this condition will apply it means element is not already sorted
                temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            return;
        }
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array after sorting
    adaptiveBubbleSort(A, n);
    printArray(A, n);
    return 0;
}