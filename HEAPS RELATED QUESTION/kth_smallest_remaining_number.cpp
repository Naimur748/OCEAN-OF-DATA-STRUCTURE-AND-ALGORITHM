#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1, 3};

    int k = 4;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){

        if(arr[i] <= k){

            k++;
        }
        else{

            break;
        }
    }

    cout << "K-th Smallest remaining number: " << k << endl;

    return 0;
}