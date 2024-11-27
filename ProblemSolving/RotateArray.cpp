#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int k){

     k = k % size;

    for(int i=0; i<k; i++){

         int temp = arr[0];

        for(int j=0; j<size-1; j++){

            arr[j] = arr[j+1];
        }

        arr[size -1] = temp;

    }

}

void printArray(int arr[], int size){
    
     for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    printArray(arr, size);
    rotateArray(arr, size, k);

    printArray(arr, size);

  

    
}