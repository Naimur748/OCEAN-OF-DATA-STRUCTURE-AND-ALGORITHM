#include <iostream>
using namespace std;

int binarySearch(int arr[], int item, int size){

    
    int left = 0;
    int right = size - 1;

    while(left <= right){

        int mid = left + (right - left) / 2;

        if(arr[mid] == item){
            return mid;
        }

        if(arr[mid] < item){
            left = mid +1;
        }else{
            right = mid -1;
        }

    }

    return -1;
}


int main(){
    int arr[20] = {-8, -1, 2, 3, 4, 5, 6, 8, 12};

    int item = 12;
    int size = 9;

    int found = binarySearch(arr, item, size);

    if(found != -1){
        cout<<"Item is found"<<endl;
    }else{
        cout<<"Item is not found"<<endl;
    }
    return 0;
}