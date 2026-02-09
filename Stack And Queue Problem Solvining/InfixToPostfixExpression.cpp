#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '^')
        return 3;
    if(op == '*' || '/')
        return 2;
    if(op == '+' || '-')
        return 1;
}

bool isRightAssociative(char op){
    return op == '^';
}

int main(){
    
    string s = "a*(a+b)/d";

    stack<char> st;
    string postfix = "";

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z')||
            (ch >= '0' && ch <= '9')){

                postfix += ch;
            }
            else if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && 
                      (precedence(st.top()) > precedence(ch) || 
                    (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch)))){
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(ch);
        }
    }

    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    cout << "Infix Expression: " << s << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}