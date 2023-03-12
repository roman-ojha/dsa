#include <iostream>

int partition(int A[], int l, int h)
{
    int pivot = l;
    int i = l + 1;
    int j = h;
    do
    {
        while (A[i] <= A[pivot])
        {
            i++;
        }
        while (A[j] > A[pivot])
        {
            j--;
        }
        if (i < j)
        {
            std::swap(A[i], A[j]);
        }
    } while (i < j);
    std::swap(A[pivot], A[j]);
    return j;
}

void mergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int partitionIndex = partition(A, l, h);
        mergeSort(A, l, partitionIndex - 1);
        mergeSort(A, partitionIndex + 1, h);
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;
    mergeSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    return 0;
}