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

void bubble_sort(int arr[], int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

int main()
{
    int n;
    n = 9;
    int *arr = new int[n]{13, 8, 7, 16, 15, 3, 19, 2, 21};
    print_array(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}