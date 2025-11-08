#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(vector<int>& arr){

    int n = arr.size();
    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        int currentCost = 0;

        for(int j = 0; j < n; j++){
            currentCost += abs(arr[j] - arr[i]);
        }

        ans = min(ans, currentCost);
    }
    return ans;
}


int main() {
    vector<int> arr = {1, 100, 101};
    cout << minCost(arr) << endl;
    
    return 0;
}

