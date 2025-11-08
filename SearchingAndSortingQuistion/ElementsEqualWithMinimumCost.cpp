#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
using ll = long long;


/*



//[Naive Approach] Using 2 Nested Loops - O(n^2) time and O(1) space
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

*/

//[Expected Approach - 2] Using Median - O(n log n) time and O(1) space

ll calculateTotalCost(const vector<ll>& numbers, ll targetValue){

    ll totalCost = 0;
    for(ll num : numbers){
        totalCost += llabs(num - targetValue);
    }

    return totalCost;
}


ll findMinimumCost(vector<ll> numbers){
    int n = numbers.size();
    if(n == 0) return 0;

    sort(numbers.begin(), numbers.end());

    ll medianValue = numbers[n / 2];

    ll minimumCost = calculateTotalCost(numbers, medianValue);

    return minimumCost;

}




int main() {
    // vector<int> arr = {1, 100, 101};
    // cout << minCost(arr) << endl;
    
    // return 0;


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage
    vector<ll> exampleArray = {1, 100, 101};

    ll result = findMinimumCost(exampleArray);

    cout << "Minimum cost to make all elements equal: " << result << '\n';
    return 0;
}

