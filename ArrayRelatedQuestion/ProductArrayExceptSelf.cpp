#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){

    int n = nums.size();
    vector<int> answer(n, 1);

    for(int i=1; i<n; i++){
        answer[i] = answer[i-1] * nums[i-1];
    }

    int suffix =1;
    for(int i=n-1; i>=0; i--){
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main(){

    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);

    for(int x : ans) cout << x <<" ";
}