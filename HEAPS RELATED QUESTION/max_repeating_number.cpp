#include <bits/stdc++.h>
using namespace std;

int maxRepeating(vector<int>& arr, int k){

    int n = arr.size();

    vector<int> freq(k, 0);

    for(int i = 0; i < n; i++){

        freq[arr[i]]++;
    }

    int maxFreq = 0;

    int result = 0;

    for(int i = 0; i < k; i++){

        if(freq[i] > maxFreq){
            maxFreq = freq[i];

            result = i;
        }
    }

    return result;
}

int main(){

    vector<int> arr = {2, 2, 1, 0, 0, 1};

    int k = 3;

    int ans = maxRepeating(arr, k);

    cout << "Maximum Repeating Element: " << ans << endl;

    return 0;
}