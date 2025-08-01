#include <iostream>
using namespace std;

int main(){

    int arr[] ={3, 2, 6, -4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int currentSum = arr[0];
    int maxSum = arr[0];
    
    for(int i=1; i<n; i++){

        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(currentSum, maxSum);

    }

    cout<<"Maximum sum is: "<<maxSum<<endl;

    return 0;
}
