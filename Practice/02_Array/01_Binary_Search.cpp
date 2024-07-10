#include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        cout << low << ", " << mid << ", " << high << ", " << endl;
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, size, 432);
    cout << "Index: " << index << endl;
    return 0;
}