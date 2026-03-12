#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> coin = {100, 20, 50, 10, 2, 5};
    int k = 3;

    int n = coin.size();

    sort(coin.begin(), coin.end());

    int coins_to_buy = ceil((double)n / (k + 1));

    int cost = 0;

    for(int i = 0; i < coins_to_buy; i++){

        cost += coin[i];
    }

    cout << "Minimum cost to acquire all coins: " << cost << endl;

    return 0; 
}