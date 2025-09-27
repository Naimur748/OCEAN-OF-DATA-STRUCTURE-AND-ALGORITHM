#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(const string &s){

    if(s.size() % 2 == 1) return false;

    unordered_map<char, char> match = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    stack<char> st;

    for(char c : s){

        if(c == '(' || c == '[' || c == '{'){
            st.push(c);

        }else{

            if(st.empty() || st.top() != match[c]){
                return false;
            }

            st.pop();
        

        }
    }

    return st.empty();


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;

    string s;
    for (char ch : line) {
        if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
            s.push_back(ch);
    }

    bool ans = isValid(s);
    cout << (ans ? "true" : "false") << '\n';
    return 0;
}