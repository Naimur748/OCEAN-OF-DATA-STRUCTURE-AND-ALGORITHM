#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {7, 6, 9, 2, 1};
    int k = 3;

    int n = arr.size();

    //loop for all index
    for(int i = 0; i < n-1 && k > 0; i++){

        int minIndex = i;

        //find the smallest element i to i+k 
        for(int j = i+1; j < n && j <= i+k; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        //smallest emement adjacent swap
        for(int j = minIndex; j > i; j--){
            swap(arr[j], arr[j - 1]);
        }

        //decrese k by the number of swaps performed
        k -= (minIndex - i);
    }

    //print the output
    cout << "Final Array: ";
    for(int x : arr){
        cout << x << " ";
    }

}