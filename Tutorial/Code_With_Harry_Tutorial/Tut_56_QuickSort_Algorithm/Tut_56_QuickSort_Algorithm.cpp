/*
    # Quick Sort:

    arr1 according to height:
    arr1[5]={161,175,152,180,178};
    
    1) partision:
        pivot = 161

        <---- lesser then or equal to 'pivot' at left side
        ----> greager then 'pivot' at right side
        {161,175,152,180,178}
              |           |
              i=1-->    <--j=4
        is arr1[i]>arr1['pivot'], yess i=1
        is arr1[j]<=arr1['pivot'], no j--, j=3;
        is arr1[j]<=arr1['pivot'], no j--, j=2;
        is arr1[j]<=arr1['pivot'], yes j=2;
        swap(arr1[i],arr1[j])
        {161,152,175,180,178}
              |    |
             i=1  j=2

        i++;j--;
        is arr1[i]>arr1['pivot'], yess i=2 ,j=1
        j<=i so, swap(arr1['pivot'],arr1[j]) (after doing this lesser then 'pivot' will come to front of array and grater to right)
        'pivot' index = 1
        {161,|152|,175,180,178}
        -----  |    ----------
          |    |         |
unsortedArray sorted  unsorted array

    2) Partision:
        now, pivot = 175 (first key of the unsorted array)

        do the same task again an again and again..................


    # Partitioning Process:
        1) i=low
        2) j=high
        3) pivot = low
        4) i++ until element --> pivot is found
        5) j-- until element <= pivot is found
        6) Swap A[i] & A[j] and repeat 4 & 5 until j<=i
        7) swap pivot & A[j]
*/

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

int partition(int A[], int low, int high)
{
    int pivot = A[low]; // consider first element as pivot
    int i = low + 1;
    int j = high;
    int temp;
    do
    {

        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex; // Index of pivot after partition
        partitionIndex = partition(A, low, high);
        // in single partition, element of partitionIndex is the sorted element in the array
        quickSort(A, low, partitionIndex - 1); // here we are shorting from the refrance element that will going to sort
        // or sorting left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3

    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}