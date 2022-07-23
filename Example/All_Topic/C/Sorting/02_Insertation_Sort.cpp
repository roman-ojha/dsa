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

void insertationSort(int A[], int n)
{
    int j, key;
    for (int i = 0; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    cout << endl;
}

int main()
{
    int A[] = {54, 76, 32, 43, 65, 12, 2, 32, 4};
    int n = 9;
    printData(A, n);
    insertationSort(A, n);
    printData(A, n);
    return 0;
}