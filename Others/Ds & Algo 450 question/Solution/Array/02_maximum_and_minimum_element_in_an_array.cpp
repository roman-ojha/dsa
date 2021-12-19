// Find the maximum and minimum element in an array

#include <iostream>
#include <stdio.h>
using namespace std;

void maximum(int *arr, int n, int *max)
{
    *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (*max < arr[i])
        {
            *max = arr[i];
        }
    }
}
void minimum(int arr[], int n, int *min)
{
    *min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (*min > arr[i])
        {
            *min = arr[i];
        }
    }
}

int main()
{
    int arr[] = {4, 5, 1, 2, 9, 3, 12, 43};
    int n = 8;
    int max, min;
    maximum(arr, n, &max);
    minimum(arr, n, &min);
    cout << "Maximum value is: " << max << endl;
    cout << "Minium value is: " << min << endl;
    return 0;
}