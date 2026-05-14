#include <bits/stdc++.h>
using namespace std;


int findKthLargest(vector<int>& arr, int k){
    
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int num : arr){

        minHeap.push(num);

        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    return minHeap.top();
}




int main(){
    
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    int k = 2;

    int ans = findKthLargest(arr, k);

    cout << k << "th largest element is: " << ans << endl;

    return 0;

}