#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int u_array)
{
    for (int i = 0; i < u_array; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insersion(int arr[], int u_array, int index, int value)
{
    for (int i = u_array - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

void deletion(int arr[], int u_array, int index)
{
    for (int i = index; i < u_array; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {1, 54, 78, 97};
    int used_array = 4;
    printf("Array before insertion: ");
    display(arr, used_array);
    insersion(arr, used_array, 1, 98);
    used_array++;
    printf("Array after insertion: ");
    display(arr, used_array);
    printf("Array afte deletion: ");
    deletion(arr, used_array, 2);
    used_array--;
    display(arr, used_array);
    return 0;
}