#include <iostream>
#include <stdio.h>
using namespace std;
void printData(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

void selectionSort(int A[], int n)
{
    int min_Index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min_Index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[min_Index] > A[j])
            {
                min_Index = j;
            }
        }
        swap(A[min_Index], A[i]);
    }
    cout << endl;
}

int main()
{
    int A[] = {54, 76, 32, 43, 65, 12, 2, 32, 4};
    int n = 9;
    printData(A, n);
    selectionSort(A, n);
    printData(A, n);
    return 0;
}