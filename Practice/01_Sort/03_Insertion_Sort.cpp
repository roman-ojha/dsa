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

void insertion_sort(int arr[], int n)
{
    int elm;
    int j;
    for (int i = 1; i < n; i++)
    {
        elm = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > elm)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = elm;
    }
}

int main()
{
    int n;
    n = 9;
    int *arr = new int[n]{13, 8, 7, 16, 15, 3, 19, 2, 21};
    print_array(arr, n);
    insertion_sort(arr, n);
    print_array(arr, n);
    return 0;
}