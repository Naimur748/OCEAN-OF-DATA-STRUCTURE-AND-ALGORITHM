#include <bits/stdc++.h>
using namespace std;


int main(){

    vector<int> arr = {10, 12, 12, 10, 10, 11, 10};

    int n = arr.size();

    int maxLen = 0;

    for(int i = 0; i < n; i++){

        int minVal = INT_MAX;

        int maxVal = INT_MIN;

        unordered_set<int> st;

        for(int j = i; j < n; j++){

            if(st.find(arr[j]) != st.end()){

                break;
            }

            st.insert(arr[j]);

            minVal = min(minVal, arr[j]);

            maxVal = max(maxVal, arr[j]);


            if(maxVal - minVal == j - i){

                int currentLen = j - i + 1;

                maxLen = max(maxLen, currentLen);
            }
        }
    }

    cout << "Length of Lonngest Contiguous Subarray = "
    << maxLen << endl;
}