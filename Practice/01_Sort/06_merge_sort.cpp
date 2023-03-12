#include <iostream>
using namespace std;

void merge(int A[], int l, int h, int m)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int B[100];
    while (i <= m && j <= h)
    {
        if (A[i] > A[j])
        {
            B[k] = A[j];
            j++;
            k++;
        }
        else
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }
    while (i <= m)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void merge_sort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, h);
        merge(A, l, h, mid);
    }
}

int main()
{

    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;
    merge_sort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    return 0;
}