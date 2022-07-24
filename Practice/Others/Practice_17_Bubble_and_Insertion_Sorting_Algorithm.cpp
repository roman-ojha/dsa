#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void bubbleSorting(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int temp, key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 3, 7, 2, 4, 1, 9, 8, 0};
    cout << "Before sorting" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    // bubbleSorting(arr, 9);
    insertionSort(arr, 9);
    cout << "\nAfter sorting" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
}