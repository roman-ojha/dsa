#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    clock_t start, endt;
    start = clock();
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    // Bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    endt = clock();
    endt = clock();
    float time = (float)(endt - start) / CLOCKS_PER_SEC;
    cout << "\nName: Roman Ojha" << endl;
    cout << "Roll: 25" << endl;
    cout << "Time: " << time << endl;
    getchar();
    return 0;
}
