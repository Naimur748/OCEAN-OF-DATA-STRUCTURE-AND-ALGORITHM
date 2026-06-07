#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k){

    vector<int> result;

    deque<int> dq;

    for(int i = 0; i < arr.size(); i++){

        while(!dq.empty() && dq.front() <= i - k){

            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] < arr[i]){

            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k - 1){

            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main(){

    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    int k = 3;

    vector<int> ans = maxSlidingWindow(arr, k);

    cout << "Maximum of all subarrays of size k:" << endl;

    for(int num : ans){

        cout << num << " ";

    }

    cout << endl;

    return 0;
}