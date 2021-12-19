#include <stdio.h>

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // code for Insertion
    if (size >= capacity)
    {
        return -1;
    }
    // this is the way to insert element in array
    // time complaxity of the given problem is O(n)
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;
    display(arr, size);
    indInsertion(arr, size, element, 100, index);
    // 'size' for how much size we have been used
    // 'element' for value of element you want to insert
    // 'index' for in which index to insert
    size += 1;
    display(arr, size);
    return 0;
}