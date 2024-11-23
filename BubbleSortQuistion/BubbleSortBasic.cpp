#include <iostream>
using namespace std;


void bubleSort(int arr[], int n){

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-i-1; j++){

            if(arr[j] > arr[j+1]){

                int temp = arr[j];

                arr[j] = arr[j+1];

                arr[j+1] = temp;
            }
        }

    }
}

int main(){

    int arr[] = {34, 22,54, 42, 78, 55, 33};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubleSort(arr, n);

    //Final array print bellow
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}