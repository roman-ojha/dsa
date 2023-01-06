#include <iostream>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void selection_sort(int arr[], int n)
{
    int min, temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    n = 9;
    int *arr = new int[n]{13, 8, 7, 16, 15, 3, 19, 2, 21};
    print_array(arr, n);
    selection_sort(arr, n);
    print_array(arr, n);
    return 0;
}