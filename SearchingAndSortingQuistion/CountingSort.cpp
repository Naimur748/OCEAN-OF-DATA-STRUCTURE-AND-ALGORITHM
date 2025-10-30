#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countsort(vector<int>& arr){

    int n = arr.size();

    int maxVal = 0;
    for(int i=0; i<n; i++){
        maxVal = max(maxVal, arr[i]);
    }

    vector<int> cntArr(maxVal + 1, 0);

    for(int j=0; j < n; j++)
       cntArr[arr[j]]++;

    for(int i=1; i <= maxVal; i++)
        cntArr[i] += cntArr[i - 1];

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
       ans[cntArr[arr[i]] - 1] = arr[i];
       cntArr[arr[i]]--;

    }

    return ans;

    


}

int main(){

    vector<int> arr = {2,5,3,0,2,3,0,3};
    vector<int> ans = countsort(arr);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}