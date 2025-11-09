#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canBeSortedByReversing(vector<int>& arr){

    int n = arr.size();
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    int left = 0, right = n - 1;

    // find first mismatch from left
    while(left < n && arr[left] == sortedArr[left]) left++;

    // find first mismatch from right
    while(right >= 0 && arr[right] == sortedArr[right]) right--;

    if(left >= right) return true;

    for(int i = left; i < right; i++){
        if(arr[i] < arr[i + 1]) return false;
    }



}


int main() {
    vector<int> arr = {1, 2, 5, 4, 3};
    if (canBeSortedByReversing(arr))
        cout << "Yes\n";
    else
        cout << "No\n";
}