#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int left = 0, right = size-1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] < target){
            left = mid + 1;
        }else{
            right =  mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 2;

    int result = binarySearch(arr, size, target);

    if(result != -1){
        cout<<"The result is : "<<result<<endl;
    }else{
        cout<<"The result is not Found : "<<endl;
    }
    return 0;
}