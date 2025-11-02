
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;



//[Naive Approach] Using 2 Nested Loops - O(n^2) time and O(1) space

/*

bool findPair(vector<int>& arr, int x){

    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            
            if(abs(arr[i] - arr[j])  == x){
                return true;
            }
        }
    }

    return false;
}

*/


// [Expected Approach - 1] Using Sorting and Binary Search - O(n Log n) time and O(1) space

/*


bool findPair(vector<int>& arr, int x){

    sort(arr.begin(), arr.end());

    int n = arr.size();

    for(int i = 0; i < n; i++){

        int target = arr[i] + x;

        if(binary_search(arr.begin() + i + 1, arr.end(), target)){
            return true;
        }
    }

    return false;

}

*/

// [Expected Approach - 2] Using Sorting and 2 Pointers Method - O(n Log n) time and O(1) space

/*

bool findPair(vector<int>& arr, int x){

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int j = 1;

    for(int i=0; i<n; i++){

        while(j<n && arr[j] - arr[i] < x ) j++;

        if(j<n && i != j && arr[j] - arr[i] == x) return true;
    }

    return false;
}

*/

//[Expected Approach - 3] Using Hash Set - O(n) time and O(n) space


bool findPair(vector<int>& arr, int x){

    unordered_set<int> seen;

    bool found = false;

    for(long long v : arr){

        if(seen.count(v - x) || seen.count(v + x)){
            found = true;
            break;
        }

        seen.insert(v);
    }

    return found;

}





int main() {
    vector<int> arr = {5, 20, 3, 2, 50, 80};
    int x = 78;
    if (findPair(arr, x)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}