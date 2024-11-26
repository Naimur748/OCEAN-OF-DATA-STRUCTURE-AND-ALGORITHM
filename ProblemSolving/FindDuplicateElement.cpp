#include <iostream>
#include <unordered_set>
using namespace std;

void removeDuplicateElement(int arr[], int size){

    unordered_set<int> seen;

    for(int i=0; i<size; i++){
        if(seen.find(arr[i]) != seen.end()){
            cout<<arr[i]<<" ";
        }else{
            seen.insert(arr[i]);
        }
    }

}


int main(){
    int arr[] = {1, 2, 3, 4, 2, 5, 6,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicateElement(arr, size);
   
   
    
}