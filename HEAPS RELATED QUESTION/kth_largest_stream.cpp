#include <bits/stdc++.h>
using namespace std;


vector<int> kthLargestStream(vector<int>& arr, int k){

    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> result;

    for(int i = 0; i < arr.size(); i++){

        minHeap.push(arr[i]);

        if(minHeap.size() > k){
            minHeap.pop();
        }

        if(minHeap.size() < k){

            result.push_back(-1);
        }
        else{
            result.push_back(minHeap.top());
        }
    }
    return result;


}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int k = 4;

    vector<int> answer = kthLargestStream(arr, k);

    cout << "Kth Largest Elements: ";

    for(int i = 0; i < answer.size(); i++){

        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}