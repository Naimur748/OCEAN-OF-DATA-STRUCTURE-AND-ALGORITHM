#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

// class Solution{
//     public:

//     int maximumProfit(vector<int>& prices){
      

//         int min_price = INT_MAX;
//         int max_profit = 0;

//         for(int price : prices){
//             if(price < min_price){
//                 min_price = price;
//             }else{
//                 int profit = price - min_price;
//                 max_profit = max(max_profit, profit);
//             }

//         }

//         return max_profit;
//     }

// };


class Solution{
    public:

    int maximumProfit(vector<int>& prices){

        int min_price = INT_MAX;
        int max_profit = 0;

        for(int price : prices){

            if(price < min_price){
                min_price = price;
            }else{
                int profit = price - min_price;
                max_profit = max(max_profit, profit);

            }
        }

        return max_profit;
    }
};




int main(){

    Solution sol;
    vector<int> prices = {7, 1, 3, 5, 2, 8};

    int result = sol.maximumProfit(prices);

    cout<<"The maximum profit is: "<<result<<endl;

    return 0;

}