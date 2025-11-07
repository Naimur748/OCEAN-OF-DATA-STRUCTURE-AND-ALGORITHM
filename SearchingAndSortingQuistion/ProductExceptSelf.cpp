#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& arr){

    int n = arr.size();
    vector<int> res (n, 1);

    //prefix product;
    for(int i = 1; i < n; ++i){
        res[i] = res[i - 1] * arr[i - 1];
    }

    //Multiply by suffix product
    int rightProd = 1;
    for(int i = n - 1; i >= 0; i-- ){
        res[i] = res[i] * rightProd;
        rightProd *= arr[i];
    }

    return res;




}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    vector<int> arr = {10, 3, 5, 6, 2};

   
    vector<int> res = productExceptSelf(arr);

    
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }

    return 0;
}