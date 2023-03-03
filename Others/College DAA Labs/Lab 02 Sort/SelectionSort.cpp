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
    // selection sort
    int min;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    endt = clock();
    endt = clock();
    float time = (float)(endt - start)/ CLOCKS_PER_SEC;
    cout<<"Name: Roman Ojha"<<endl;
    cout<<"Roll: 25"<<endl;
    cout<<"Time: "<<time<<endl;
    return 0;
}
