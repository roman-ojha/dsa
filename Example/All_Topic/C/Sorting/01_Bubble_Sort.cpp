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

void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }
    cout << endl;
}

void adaptiveBubbleSort(int A[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    cout << endl;
}

int main()
{
    int A[] = {54, 76, 32, 43, 65, 12, 2, 32, 4};
    int n = 9;
    printData(A, n);
    // bubbleSort(A, n);
    adaptiveBubbleSort(A, n);
    printData(A, n);
    return 0;
}