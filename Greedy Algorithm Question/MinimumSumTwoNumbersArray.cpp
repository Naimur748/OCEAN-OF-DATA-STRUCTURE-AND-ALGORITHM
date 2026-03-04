#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {6, 8, 4, 5, 2, 3};

    sort(arr.begin(), arr.end());
    
    long long num1 = 0;
    long long num2 = 0;

    for(int i = 0; i < arr.size(); i++){

        if( i % 2 == 0){

            num1 = num1 * 10 + arr[i];
        }else{
            num2 = num2 * 10 + arr[i];
        }
    }

    long long result = num1 + num2;

    cout << result;

    return 0;
}
