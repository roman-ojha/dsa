#include <stdio.h>

int linearSearch(int arr[], int n, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int size)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            return mid;
        }
        else if (n > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int array[11] = {2, 10, 27, 38, 41, 60, 79, 100, 173, 199, 237};
    int Lires, Bires;
    int size = sizeof(array) / sizeof(int);
    Lires = linearSearch(array, 38, size);
    printf("Linear Searching:\n");
    if (Lires >= 0)
    {
        printf("Search found at the index no. %d\n", Lires);
    }
    else
    {
        printf("Sorry Search not found!! plese try again letter\n");
    }
    Bires = binarySearch(array, 41, size);
    printf("Binary Searching:\n");
    if (Bires >= 0)
    {
        printf("Search found at the index no. %d", Bires);
    }
    else
    {
        printf("Sorry Search not found!! plese try again letter");
    }
    return 0;
}