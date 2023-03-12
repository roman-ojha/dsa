#include <iostream>

void heapify(int A[], int n, int i)
{
    int largest = i;
    // int parent = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    int lChild;
    if (left < n && A[left] > A[largest])
    {
        largest = left;
    }
    if (right < n && A[right] > A[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(A[largest], A[i]);
        heapify(A, n, largest);
    }
}

void heap_sort(int A[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(A, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;
    heap_sort(A, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    return 0;
}