#include <bits/stdc++.h>
using namespace std;

bool isValid(int num){

    string s = to_string(num);

    stack<char> st;

    for(int i = 0; i < s.length(); i++){

        if(st.empty()){

            st.push(s[i]);

        }else{

            if(s[i] < st.top()){
                return false;

            }else{

                st.push(s[i]);

            }

        }
    }

    return true;
}

int main(){

    int n = 10;

    int count = 0;

    for(int i = 1; i <= n; i++){

        if(isValid(i)){
            count++;
        }
    }
    cout << "Count of valid Number: " << count << endl;

    return 0;
}