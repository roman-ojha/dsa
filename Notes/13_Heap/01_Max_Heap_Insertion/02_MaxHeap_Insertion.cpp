#include <iostream>
using namespace std;

class MaxHeap
{
public:
    void insert(int arr[], int *n, int val)
    {
        *n = *n + 1;
        arr[*n - 1] = val;
        int i = *n - 1;
        while (i >= 0)
        {
            int parent = i / 2;
            if (arr[i] > arr[parent])
            {
                // swap child with parent
                int temp = arr[i];
                arr[i] = arr[parent];
                arr[parent] = temp;
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    void display(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size = 20;
    // Max heap
    int arr[20] = {70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5};
    int *arr2 = new int[size]{70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5};
    int n = 11;

    MaxHeap mh;
    // mh.display(arr2, n);
    mh.display(arr, n);
    mh.insert(arr, &n, 33);
    mh.display(arr, n);

    return 0;
}