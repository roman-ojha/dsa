#include <iostream>
#include <stdio.h>
using namespace std;

void displayHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertation(int A[], int *n, int value)
{
    *n = *n + 1;
    A[*n - 1] = value;
    int i = *n - 1;
    int parent;
    while (i > 0)
    {
        parent = i / 2;
        if (A[parent] < A[i])
        {
            swap(A[parent], A[i]);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int A[20] = {70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5};
    int n = 11;
    int value = 61;
    insertation(A, &n, value);
    displayHeap(A, n);
    return 0;
}