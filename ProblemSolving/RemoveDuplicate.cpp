#include <iostream>
#include <unordered_set>
using namespace std;

int removeDuplicate(int arr[], int size){
    unordered_set<int> seen;
    int index = 0;

    for(int i=0; i<size; i++){

        if(seen.find(arr[i]) == seen.end()){
            seen.insert(arr[i]);
            arr[index++] = arr[i];

        }
        
    }
    return index;
}

int main(){
    int arr[] = {1, 2, 4, 5, 2, 3, 6, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int newSize = removeDuplicate(arr, size);

    for(int i=0; i<newSize; i++){
        cout<<arr[i]<<" ";
    }
}