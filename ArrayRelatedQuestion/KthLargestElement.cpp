/*

215. Kth Largest Element in an Array
Medium
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/






#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int,int> findKthLargestWithIndex(const vector<int>& nums, int k){

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

    for(int i=0; i<(int)nums.size(); i++){
        minHeap.push({nums[i], i});

        if((int)minHeap.size() > k){
            minHeap.pop();
        }
    }

    return minHeap.top();
}


int main(){

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    pair<int, int> res = findKthLargestWithIndex(nums, k);

    cout<<"The" << k << " th largest element is: "<<res.first<<" at index: "<<res.second<<endl;

    return 0;
}