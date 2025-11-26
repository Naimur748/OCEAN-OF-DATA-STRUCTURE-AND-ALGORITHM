#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int>& arr){

    int n = arr.size();

    vector<pair<int,int>> vcc(n);

    for(int i=0; i<n; i++){
        vcc[i].first = arr[i];
        vcc[i].second = i;
    }

    sort(vcc.begin(), vcc.end());

    vector<bool> visited (n, false);
    int swaps = 0;

    for(int i=0; i<n; i++){

        if(visited[i] || vcc[i].second == i)
            continue;

            int cycle_size = 0;
            int j = i;

            while(!visited[j]){
                visited[j] = true;
                j = vcc[j].second;
                cycle_size++;
            }

            if(cycle_size > 1){
                swaps += (cycle_size - 1);
            }

    }

    return swaps;

}


int main(){

    vector<int> arr1 = {2, 8, 5, 4};
    vector<int> arr2 = {10, 19, 6, 3, 5};
    vector<int> arr3 = {1, 3, 4, 5, 6};
    
    cout << minSwaps(arr1) << endl;  // 1
    cout << minSwaps(arr2) << endl;  // 2
    cout << minSwaps(arr3) << endl;  // 0
    
    return 0;
}