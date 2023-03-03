#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

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
    // Insertion sort
    int pivote,i,j;
    for(i=1;i<n;i++){
        pivote = i;
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                arr[j+1] = arr[j];
            }
        }
        arr[j] = arr[pivote];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    endt = clock();
    endt = clock();
    float time = (float)(endt - start)/ CLOCKS_PER_SEC;
    cout<<"\nName: Roman Ojha"<<endl;
    cout<<"Roll: 25"<<endl;
    cout<<"Time: "<<time<<endl;
    return 0;
}
