#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*




vector<vector<int>> findRiskNeutralPortfolios(vector<int>& profitLossList){
    
    vector<vector<int>> riskFreeCombos;

    int n = profitLossList.size();

    if(n < 3) return riskFreeCombos;

    sort(profitLossList.begin(), profitLossList.end());

    for(int i=0; i<= n-3; ++i){

        if(i > 0 && profitLossList[i] == profitLossList[i-1]) continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right){

            int  total = profitLossList[i] + profitLossList[left] + profitLossList[right];

            if(total == 0){
                
                riskFreeCombos.push_back({profitLossList[i], profitLossList[left], profitLossList[right]});

                int leftVal = profitLossList[left];
                while(left < right && profitLossList[left] == leftVal) ++left;

                int rightVal = profitLossList[right];
                while(left < right && profitLossList[right] == rightVal) --right;

            } 
            else if(total < 0){

                ++left;
            }
            else{

                --right;
            }

            
        }
    }

    return riskFreeCombos;
};

void printPortfolios(const vector<vector<int>>& portfolios) {
    for (auto &p : portfolios) {
        cout << "[ ";
        for (int value : p) {
            cout << value << " ";  
        }
        cout << "]\n"; 
    }
}



int main(){
    vector<int> profitLossList = {-200, 100, 100, 50, -50, 0};

    auto portfolios = findRiskNeutralPortfolios(profitLossList);

    cout << "Risk-neutral portfolios found: " << portfolios.size() << "\n";

    printPortfolios(portfolios);

    return 0;


}

*/


class Solution{
    public:

    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-2; i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = n-1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right --;

                    left++;
                    right--;

                }else if(sum < 0){

                    left++;

                }else{

                    right--;
                }

            }
        }

        return result;

    }

};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Output: \n";
    for(auto triplet : ans) {
        cout << "[";
        for(int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if(i < triplet.size()-1) cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}