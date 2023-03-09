#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int B[100000];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
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
    // Merge sort
    mergeSort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    endt = clock();
    endt = clock();
    float time = (float)(endt - start) / CLOCKS_PER_SEC;
    cout << "\nName: Roman Ojha" << endl;
    cout << "Roll: 25" << endl;
    cout << "Time: " << time << endl;
    return 0;
}
