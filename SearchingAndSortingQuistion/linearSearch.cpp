#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size){

    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return key;
        }
    }
    return -1;
}

int main(){
    int arr[20] = {4, 5, 8, 12, 47, -2,-5};

    int key = 5;

    int size = 7;

int found = linearSearch(arr, key, size);

    if(found){
        cout<<"Searching Item found"<<endl;
    }else{
        cout<<"Searching Item NOt found"<<endl;
    }
}