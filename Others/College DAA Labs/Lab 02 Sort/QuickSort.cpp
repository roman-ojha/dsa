#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int partition(int A[],int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {

        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[],int low,int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(A,low,high);
        quickSort(A,low,partitionIndex - 1);
        quickSort(A,partitionIndex+1, high);
    }
}

int main(){
    clock_t start, endt;
    start = clock();

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++){
        arr[i] = rand();
    }
    // Quick Sort
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    endt = clock();
    float time = (float)(endt - start)/ CLOCKS_PER_SEC;
    cout<<"\nName: Roman Ojha"<<endl;
    cout<<"Roll: 25"<<endl;
    cout<<"Time: "<<time<<endl;
    return 0;
}
