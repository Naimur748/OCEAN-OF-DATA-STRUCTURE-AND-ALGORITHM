#include <bits/stdc++.h>
using namespace std;



int smallestMissingPositive(vector<int>& arr){

    unordered_set<int> st;

    for(int num : arr){

        if(num > 0){

            st.insert(num);
        }
    }

    int missing = 1;

    while(st.find(missing) != st.end()){

        missing++;
    }

    return missing;
}

int main(){

    vector<int> arr = {2, -3, 4, 1, 1, 7};

    int result = smallestMissingPositive(arr);

    cout << "Smallest Missing Positive Number = "
            << result << endl;

    return 0;
}