#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = 2;

    unordered_map<int, int> freq;

    for(int num : nums){

        freq[num]++;

    }

    priority_queue<pair<int, int>> maxHeap;

    for(auto it : freq){
        maxHeap.push({it.second, it.first});
    }

    vector<int> result;

    while(k--){

        pair<int, int> topElement = maxHeap.top();

        maxHeap.pop();

        result.push_back(topElement.second);
    }

    cout << "Top K Frequent Element: ";

    for(int num : result){
        cout << num << " ";
    }

    cout << endl;

    return 0;


}