#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n){

    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){

        while(!st.empty() && arr[i] < arr[st.top()]){

            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;


}

int main(){

    vector<int> arr = {4, 8, 5, 2, 25};

    int n = arr.size();

    vector<int> ans = nextSmallerElement(arr, n);

    cout << "Next Smaller Element: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}