#include <bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int i){

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){

        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }

}





//Heap sort function
void heapSort(int arr[], int n){

    for(int i = n / 2 - 1; i >= 0; i--){

        heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; i--){

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}






//Array print function
void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){

        cout << arr[i] << " ";
    }
    cout << endl;
}


 int main(){

        int arr[] = {4, 10, 3, 5, 1};

        int n = sizeof(arr) / sizeof(arr[0]);

        cout << "Before Heap Sort: " << endl;
        printArray(arr, n);

        //Heap sort call
        heapSort(arr, n);

        cout << "After Heap sort: " << endl;
        printArray(arr, n);
    }

   

