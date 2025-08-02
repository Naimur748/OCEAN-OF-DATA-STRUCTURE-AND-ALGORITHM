
// Chocolate Distribution Problem
// Last Updated : 23 Jul, 2025
// Given an array arr[] of n integers where arr[i] represents
//  the number of chocolates in ith packet. Each packet can have a variable number 
//  of chocolates. There are m students, the task is to distribute chocolate packets
//  such that: 

// Each student gets exactly one packet.
// The difference between the maximum and minimum number of chocolates in the packets given to the students is minimized.
// Examples:

// Input: arr[] = {7, 3, 2, 4, 9, 12, 56}, m = 3 
// Output: 2 
// Explanation: If we distribute chocolate packets {3, 2, 4}, we will get the minimum difference, that is 2. 

// Input: arr[] = {7, 3, 2, 4, 9, 12, 56}, m = 5 
// Output: 7
// Explanation: If we distribute chocolate packets {3, 2, 4, 9, 7}, we will get the minimum difference, that is 9 - 2 = 7. 




#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int findMinDiff(int arr[], int n, int m){

    if (n < m) return -1;

    sort(arr, arr + n);

    int min_diff = INT_MAX;

    for(int i=0; i+m-1<n; i++){

        int diff = arr[i+m-1] - arr[i];

        min_diff = min(min_diff, diff);

    }

    return min_diff;

}


int main(){

    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n  = sizeof(arr) / sizeof(arr[0]);

    int m = 3;

    cout<<"Minimum difference is " <<findMinDiff(arr, n, m);

    return 0;
}

