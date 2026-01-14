#include <bits/stdc++.h>
using namespace std;

bool backtrack(vector<int>& arr, vector<int>& subsetSum, int index, int target){

    if(index == arr.size()){
        for(int i = 0; i < subsetSum.size(); i++){
            if(subsetSum[i] != target)
                return false;
        }
        return true;
    }

    for(int i = 0; i < subsetSum.size(); i++){
        
        if(subsetSum[i] + arr[index] > target)
            continue;

            subsetSum[i] += arr[index];

            if(backtrack(arr, subsetSum, index + 1, target))
                return true;
            
            subsetSum[i] -= arr[index];

            if(subsetSum[i] == 0)
                break;
    }

    return false;
    
}


bool canPartitionKSubsets(vector<int>& arr, int k){

    int totalSum = 0;

    for(int x : arr){
        totalSum += x;
    }

    if(totalSum % k != 0){
        return false;
    }

    int target = totalSum / k;

    for(int x : arr){
        if(x > target)
            return false;
    }

    vector<int> subsetSum(k, 0);

    sort(arr.rbegin(), arr.rend());

    return backtrack(arr, subsetSum, 0, target);



}


int main() {

    // ইনপুট হার্ডকোড করা (cin ব্যবহার করা হয়নি)
    vector<int> arr = {2, 1, 4, 5, 6};
    int k = 3;

    bool result = canPartitionKSubsets(arr, k);

    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}