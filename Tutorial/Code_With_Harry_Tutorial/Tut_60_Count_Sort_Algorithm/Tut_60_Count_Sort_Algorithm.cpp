/*
    # Count sort
        -> One of the fastest Algorithm

    Count Sort process
        arr1[7]=3,1,9,7,1,2,4 -> maxVal=9

        so, maxVal=9 create new array of arr2[10]
        0,0,0,0,0,0,0,0,0

    1) 
        0,0,0,1,0,0,0,0,0,0 -> arr1[0]=3, so arr2[3]++;
        0,1,0,0,0,0,0,0,0,0 -> arr1[1]=1, so arr2[1]++;
        0,1,0,1,0,0,0,0,0,1 -> arr1[2]=9, so arr2[9]++;
        0,1,0,1,0,0,0,1,0,1 -> arr1[3]=7, so arr2[7]++;
        0,2,0,1,0,0,0,1,0,1 -> arr1[4]=1, so arr2[1]++;
        0,2,1,1,0,0,0,1,0,1 -> arr1[5]=2, so arr2[2]++;
        0,2,1,1,1,0,0,1,0,1 -> arr1[6]=4, so arr2[4]++;

        --->travers
        now make a new array, arr3[7]
        0,2,1,1,1,0,0,1,0,1 -> arr2[0]=0 -> move to next index
        0,2,1,1,1,0,0,1,0,1 -> arr2[1]=2 -> decrement 2--
              1, , , , , ,  -> arr3[0]=1(index of arr2[1])
        0,1,1,1,1,0,0,1,0,1 -> arr2[1]=1 -> decrement 1--
              1,1, , , , ,  -> arr3[1]=1(index of arr2[1])
        0,0,1,1,1,0,0,1,0,1 -> arr2[1]=0 -> move to next index
        0,0,1,1,1,0,0,1,0,1 -> arr2[2]=1 -> decrement 1--
              1,1,2, , , ,  -> arr3[2]=2(index of arr2[2])
        0,0,0,1,1,0,0,1,0,1 -> arr2[2]=0 -> move to next index
        0,0,0,1,1,0,0,1,0,1 -> arr2[3]=1 -> decrement 1--
              1,1,2,3, , ,  -> arr3[3]=3(index of arr2[3])
        0,0,0,0,1,0,0,1,0,1 -> arr2[3]=0 -> move to next index
        0,0,0,0,1,0,0,1,0,1 -> arr2[4]=1 -> decrement 1--
              1,1,2,3,4, ,  -> arr3[4]=4(index of arr2[4])
        0,0,0,0,0,0,0,1,0,1 -> arr2[4]=0 -> move to next index
        0,0,0,0,0,0,0,1,0,1 -> arr2[5]=0 -> move to next index
        0,0,0,0,0,0,0,1,0,1 -> arr2[6]=0 -> move to next index
        0,0,0,0,0,0,0,1,0,1 -> arr2[7]=1 -> decrement 1--
              1,1,2,3,4,7,  -> arr3[5]=7(index of arr2[7])
        0,0,0,0,0,0,0,0,0,1 -> arr2[7]=0 -> move to next index
        0,0,0,0,0,0,0,0,0,1 -> arr2[8]=0 -> move to next index
        0,0,0,0,0,0,0,0,0,1 -> arr2[9]=1 -> decrement 1--
              1,1,2,3,4,6,9 -> arr3[6]=9(index of arr2[9])
        0,0,0,0,0,0,0,0,0,0 -> arr2[9]=0 
              1,1,2,3,4,6,9 -> Sorted array

            
    -> it will take extra space count[n+1]
    -> Time Complexity = O(m+n) or O(n) => Fastest Shorting algorithm
        
*/

#include <iostream>
#include <stdio.h>
#include <climits>
#include <malloc.h>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    // Dynamically creating the array for the count

    // Initialize the array element to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Incrementing the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}