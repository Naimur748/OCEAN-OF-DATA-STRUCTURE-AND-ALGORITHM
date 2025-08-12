#include <iostream>
#include <vector>
using namespace std;

/*


int maxProduct(vector<int>& nums){

    if(nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for(int i=1; i<(int)nums.size(); ++i){

        int x = nums[i];

        if(x < 0) swap(maxProd, minProd);

        maxProd = max(x, maxProd * x);
        minProd = min(x, minProd * x);

        ans = max(ans, maxProd);

    }

    return ans;

}

*/




int maxProduct(vector<int>& nums){

    if(nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for(int i=1; i<(int)nums.size(); ++i){

        int x = nums[i];

        if(x < 0) swap(maxProd, minProd);

        maxProd = max(x, maxProd * x);

        minProd = min(x, minProd * x);

        ans = max(ans, maxProd);

    }

    return ans;

};

int main(){

    vector<int> nums1 = {2,3,-2,4};
    cout<<"Example 1 output: "<<maxProduct(nums1)<<endl;

    vector<int> nums2 = {-2,0,-1};
    cout<<"Example 2 output: " <<maxProduct(nums2)<<endl;

    return 0;
}