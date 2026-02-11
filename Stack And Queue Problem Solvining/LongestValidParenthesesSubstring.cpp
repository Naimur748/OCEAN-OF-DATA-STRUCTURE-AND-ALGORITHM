#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s){
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for(int i = 0; i < s.length(); i++){

        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();

            if(st.empty()){
                st.push(i);
            }
            else{

                int currentLen = i - st.top();
                maxLen = max(maxLen, currentLen);
            }
        }

    }

    return maxLen;
}

int main(){

    string s = "(()())";

    int result = longestValidParentheses(s);

    cout << "Longest Valid Parentheses Length: " << result << endl;

    return 0;
}