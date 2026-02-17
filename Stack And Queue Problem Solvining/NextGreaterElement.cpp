#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1, 3, 2, 4};

    int n = arr.size();
    
    vector<int> result(n, -1);
    
    stack<int> st;

    for(int i = 0; i < n; i++){

        while(!st.empty() && arr[i] > arr[st.top()]){

            result[st.top()] = arr[i];

            st.pop();
        }

        st.push(i);
    }

    cout << "Next Greater Element: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    return 0;
}