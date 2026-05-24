#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};

    int k = 4;

    unordered_map<int, int> freq;

    for(int i = 0; i < k; i++){

        freq[arr[i]]++;
    }

    cout << freq.size() << " ";

    for(int i = k; i < arr.size(); i++){

        int outgoing = arr[i - k];

        freq[outgoing]--;

        if(freq[outgoing] == 0){

            freq.erase(outgoing);
        }

        int incoming = arr[i];

        freq[incoming]++;

        cout << freq.size() << " ";
    }

    return 0;
}