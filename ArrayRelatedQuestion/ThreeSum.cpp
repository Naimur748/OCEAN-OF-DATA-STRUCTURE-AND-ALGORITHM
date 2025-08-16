#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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