#include <iostream>
#include <vector>
using namespace std;

// int findMinOps(vector<int>& arr){

//     int n = arr.size();
//     int i = 0, j = n - 1;
//     int ans = 0;

//     while(i < j){

//         if(arr[i] == arr[j]){
//             i++;
//             j--;
//         }else if(arr[i] < arr[j]){

//             arr[i + 1] += arr[i];
//             i++;
//             ans++;

//         }else{

//             arr[j -1] += arr[j];
//             j--;
//             ans++;

//         }
//     }

//     return ans;
// }







int findMinOps(vector<int>& arr){


    int n = arr.size();
    int i = 0, j=n-1;
    int ans = 0;

    while(i < j){

        if(arr[i] == arr[j]){
            
            i++;
            j--;

        }else if(arr[i] < arr[j]){

            arr[i+1] += arr[i];
            i++;
            ans++;

        }else{

            arr[j-1] += arr[j];
            j--;
            ans++;

        }


    }

    return ans;

}








int main(){

    vector<int> arr1 = {15, 4, 15};
    cout << "Minimum operations: " << findMinOps(arr1) << endl;
    // Output: 0

    vector<int> arr2 = {1, 4, 5, 1};
    cout << "Minimum operations: " << findMinOps(arr2) << endl;
    // Output: 1

    vector<int> arr3 = {11, 14, 15, 99};
    cout << "Minimum operations: " << findMinOps(arr3) << endl;
    // Output: 3

    return 0;

}