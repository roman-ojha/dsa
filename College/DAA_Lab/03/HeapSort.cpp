#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

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
    if (i >= 0)
    {
        heapify(A, n, i);
        createMaxHeap(A, n, i - 1);
    }
}

void heapSort(int A[], int n)
{
    int temp;
    createMaxHeap(A, n, n / 2);
    for (int i = n - 1; i >= 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}

int main()
{
    clock_t start, endt;
    start = clock();

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    // HeapSort
    heapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    endt = clock();
    float time = (float)(endt - start) / CLOCKS_PER_SEC;
    cout << "\nName: Roman Ojha" << endl;
    cout << "Roll: 25" << endl;
    cout << "Time: " << time << endl;
    return 0;
}
