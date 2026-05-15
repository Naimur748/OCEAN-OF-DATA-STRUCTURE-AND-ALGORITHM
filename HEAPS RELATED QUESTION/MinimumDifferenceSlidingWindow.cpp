#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};

    int m = 3;

    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;

    for(int i = 0; i + m -1 < arr.size(); i++){

        int diff = arr[i + m + 1] - arr[i];

        minDiff = min(minDiff, diff);

    }

    cout << "Minimum Difference is: " << minDiff << endl;

    return 0;
}