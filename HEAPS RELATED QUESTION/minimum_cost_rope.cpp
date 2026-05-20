#include <bits/stdc++.h>
using namespace std;


int minimumCost(vector<int>& arr){

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < arr.size(); i++){

        minHeap.push(arr[i]);
    }

    int totalCost = 0;

    while(minHeap.size() > 1){

        int first = minHeap.top();
        minHeap.pop();


        int second = minHeap.top();
        minHeap.pop();

        int cost = first + second;

        totalCost += cost;

        minHeap.push(cost);

    }
    return totalCost;
}

int main(){

    vector<int> arr = {4, 3, 2, 6};

    int answer = minimumCost(arr);

    cout << "Minimum Cost: " << answer << endl;

    return 0;
}