#include <bits/stdc++.h>
using namespace std;

bool isValidString(const string &s){

    int count = 0;

    for(char c : s){
        if(c == '('){
            count++;
        }
        else if(c == ')'){
            count--;

            if(count < 0)
                return false;
        }
    }
    return count == 0;
}

vector<string> removeInvalidParentheses(string str){

    unordered_set<string> visited;
    queue<string> q;
    vector<string> result;
    bool level = false;

    q.push(str);
    visited.insert(str);

    while(!q.empty()){

        string temp = q.front();
        q.pop();

        if(isValidString(temp)){
            result.push_back(temp);
            level = true;
        }

        if(level)
            continue;

            for(int i=0; i< temp.size(); i++){

                if(temp[i] != '(' && temp[i] != ')')
                    continue;

                    string cur = temp.substr(0, i) + temp.substr(i + 1);

                    if(visited.find(cur) == visited.end()){
                        visited.insert(cur);
                        q.push(cur);
                    }
            }
    }

    return result;

}





int main() {

    // 🔹 এখানে input হার্ডকোড করা (cin ব্যবহার করা হয়নি)
    string str = "()())()";

    // ফাংশন কল করা
    vector<string> ans = removeInvalidParentheses(str);

    // সব valid string print করা
    for (string s : ans) {
        cout << s << " ";
    }

    return 0;
}