#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int randomizePartition(int A[],int low, int high){
    int ran = (rand() % (high - low + 1)) + low;
    int temp;
    temp = A[low];
    A[low] = A[ran];
    A[ran] = temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;
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

void randomizeQuickSort(int A[],int low,int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = randomizePartition(A,low,high);
        randomizeQuickSort(A,low,partitionIndex - 1);
        randomizeQuickSort(A,partitionIndex+1, high);
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
    // Randomize quickSort
    randomizeQuickSort(arr,0,n-1);

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
