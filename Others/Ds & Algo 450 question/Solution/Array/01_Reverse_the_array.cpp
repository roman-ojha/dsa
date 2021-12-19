// Given an array (or string), the task is to reverse the array/string.
// Examples :

// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}

#include <iostream>
using namespace std;

void reverseArray(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 1, 2, 9, 3, 12, 43};
    int n = 8;
    reverseArray(arr, n);
    // printing the array
    cout << "Array after inversed:" << endl;
    printArray(arr, n);
    return 0;
}