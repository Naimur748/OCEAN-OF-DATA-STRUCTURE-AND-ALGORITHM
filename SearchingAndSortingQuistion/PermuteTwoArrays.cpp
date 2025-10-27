#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 

bool isPossible(vector<int>& a, vector<int>& b, int k){

    int n = a.size();

    sort(a.begin(), a.end());

    sort(b.begin(), b.end(), greater<int>());

    for(int i=0; i<n; i++){
        if(a[i] + b[i] < k){
            return false;
        }
    }

    return true;


}


int main(){

    vector<int> a = {2, 1, 3};
    vector<int> b = {7, 8, 9};

    int k= 10;

    isPossible(a, b, k) ? cout << "yes" : cout << "No";
    return 0;
}