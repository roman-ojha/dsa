#include <stdio.h>

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // time complexcity for this process is O(n)
    printf("\n");
}

void indDeletion(int arr[], int size, int index)
{
    // code for Deletion
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // this is the way to delete the data of the array from n index
    // time complexcity for this problem is O(n)
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 0;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}