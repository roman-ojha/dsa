// #include <stdio.h>
// #include <stdlib.h>

// // void selectionSort(int arr[], int n)
// // {
// //     int indexOfMin, temp;
// //     for (int i = 0; i < n - 1; i++)
// //     {
// //         indexOfMin = i;
// //         for (int j = i + 1; j < n; j++)
// //         {
// //             if (arr[indexOfMin] > arr[j])
// //             {
// //                 indexOfMin = j;
// //             }
// //         }
// //         temp = arr[i];
// //         arr[i] = arr[indexOfMin];
// //         arr[indexOfMin] = temp;
// //     }
// // }

// int main()
// {
//     // int arr[] = {9, 5, 6, 7, 3, 2, 8, 4, 1, 0};
//     // int n = 10;
//     // printf("Before sorting:\n");
//     // for (int i = 0; i < n; i++)
//     // {
//     //     printf("%d ", arr[i]);
//     // }
//     // selectionSort(arr, n);
//     // printf("\nAfter sorting:\n");
//     // for (int i = 0; i < n; i++)
//     // {
//     //     printf("%d ", arr[i]);
//     // }
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>
// using namespace std;

// void insertionSort(int arr[], int n)
// {
//     int temp, currentIndex, current;
//     int j;
//     for (int i = 0; i < n; i++)
//     {
//         current = arr[i];
//         for (j = i; i >= 0; j--)
//         {
//             if (current < arr[i])
//             {
//                 arr[j + 1] = arr[j];
//             }
//         }
//         arr[j + 1] = current;
//     }
// }

// int partition(int arr[], int low, int high)
// {
//     int temp;
//     int j = high;
//     int i = low + 1;
//     int key = low;
//     while (i <= j)
//     {
//         while (arr[j] > arr[low])
//         {
//             j--;
//         }
//         while (arr[i] <= arr[low])
//         {
//             i++;
//         }
//         if (i < j)
//         {

//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     temp = arr[key];
//     arr[j] = arr[key];
//     arr[key] = temp;
//     return j;
// }

// void quickSort(int arr[], int low, int high)
// {
//     int partitionIndex;
//     if (low < high)
//     {
//         partitionIndex = partition(arr, low, high);
//         quickSort(arr, low, partitionIndex - 1);
//         quickSort(arr, partitionIndex + 1, high);
//     }
// }

// void merge(int A[], int low, int mid, int high)
// {
//     int temp, B[50];
//     int i = low;
//     int j = mid + 1;
//     int k = low;

//     while (i <= mid || j <= high)
//     {
//         while (A[j] > A[i])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         while (A[j] < A[i])
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         i++;
//         k++;
//     }
//     while (j <= mid)
//     {
//         B[k] = A[j];
//         j++;
//         k++;
//     }
//     for (i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
// }

// void mergeSort(int arr[], int low, int high)
// {
//     int mid;
//     if (low < high)
//     {
//         mid = (low + high) / 2;
//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);
//         merge(arr, low, mid, high);
//     }
// }

// int main()
// {

//     return 0;
// }
