#include <iostream>
using namespace std;

int maxSubArraySum(int arr[], int n){
    int maxCurrent = arr[0];
    int maxGlobal = arr[0];

    for(int i=0; i<n; i++){
        maxCurrent = max(arr[i], maxCurrent + arr[i]);

        if(maxCurrent > maxGlobal){
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxsub = maxSubArraySum(arr, n);

    cout<<"Largest contigous Subarray Sum "<< maxsub<< endl;

    return 0;
}