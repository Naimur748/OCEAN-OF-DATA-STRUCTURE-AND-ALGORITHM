#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {6, 8, 0, 1, 3};

    int n = arr.size();

    vector<int> result(n);

    stack<int> st;

    for(int i = n -1; i >= 0; i--){

        while(!st.empty() && st.top() <= arr[i]){

            st.pop();
        }

        if(st.empty()){

            result[i] = -1;
        }
        else{

            result[i] = st.top();
        }
        st.push(arr[i]);
    }

    //Output print section
    cout << "Next Greater Element: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }

    cout << endl;

}