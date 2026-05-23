#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    int prefixSum = 0;

    int maxLen = 0;

    unordered_map<int, int> mp;

    for(int i = 0; i < arr.size(); i++){

        prefixSum += arr[i];

        if(prefixSum == 0){
            maxLen = i + 1;
        }

        if(mp.find(prefixSum) != mp.end()){

            int prevIndex = mp[prefixSum];

            int currentLen = i - prevIndex;

            maxLen = max(maxLen, currentLen);
        }
        else{

            mp[prefixSum] = i;
        }
    }

    cout << "Longest Subarray Length: " << maxLen << endl;

    return 0;
}