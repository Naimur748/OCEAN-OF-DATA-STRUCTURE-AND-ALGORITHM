#include <bits/stdc++.h>
using namespace std;

bool hasDuplicateParenthesis(string expr){

    stack<char> st;

    for( int i = 0; i < expr.length(); i++){

        char ch = expr[i];

        if(ch == ')'){

            int counter = 0;

            while(!st.empty() && st.top() != '('){
                st.pop();
                counter++;
            }

            if(!st.empty()){
                st.pop();
            }

            if(counter < 1){
                return true;
            }
        }else{

            st.push(ch);
        }
    }

    return false;
}

int main(){

    string expression = "(((a + b)) + c)";

    if(hasDuplicateParenthesis(expression)){
        cout << "Duplicate Parenthesis Found" << endl;
    }else{
        cout << "No Duplicate Parenthesis" << endl;
    }

    return 0;
}