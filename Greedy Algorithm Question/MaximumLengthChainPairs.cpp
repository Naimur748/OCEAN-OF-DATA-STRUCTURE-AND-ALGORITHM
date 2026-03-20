#include <bits/stdc++.h>
using namespace std;

int main(){

    //Hardcoded input(pair list)
    vector<pair<int, int>> pairs = {
        {5, 24},
        {39, 60},
        {15, 28},
        {27, 40},
        {50, 90}
    };

    sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });

    //Always take first pair
    int count = 1;
    int last_end = pairs[0].second;

    for(int i = 1; i < pairs.size(); i++){

        if(pairs[i].first > last_end){

            count++;
            last_end = pairs[i].second;
        }
    }

    //see the output
    cout << "Maximum Length of chain: " << count << endl;
}