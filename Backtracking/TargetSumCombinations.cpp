#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> results;

void backtrack(const vector<int>& arr, int start, int remaining, vector<int>& current){

    if(remaining == 0){
        results.push_back(current);
        return;

    }

    for(int i = start; i < (int)arr.size(); i++){

        if(arr[i] > remaining) break;

        current.push_back(arr[i]);

        backtrack(arr, i, remaining - arr[i], current);

        current.pop_back();
    }
}


int main(){

    vector<int> arr = {1, 2, 3};
    int target = 5;

    sort(arr.begin(), arr.end());

    vector<int> current;
    results.clear();


    backtrack(arr, 0, target, current);


     if (results.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (size_t i = 0; i < results.size(); ++i) {
            cout << "[";
            for (size_t j = 0; j < results[i].size(); ++j) {
                cout << results[i][j];
                if (j + 1 < results[i].size()) cout << ", ";
            }
            cout << "]";
            if (i + 1 < results.size()) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;

}