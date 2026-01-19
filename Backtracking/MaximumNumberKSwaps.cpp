#include <bits/stdc++.h>
using namespace std;

string maxString;

void findMaximum(string &s, int k, int index){
    if(k == 0){
        return;
    }

    int n = s.length();

    char maxDigit = s[index];
    for(int i = index + 1; i < n; i++){
        if(s[i] > maxDigit)
            maxDigit = s[i];
    }

    if(maxDigit != s[index])
        k--;
    
    for(int i = index; i < n; i++){
        if(s[i] == maxDigit){

            swap(s[index], s[i]);

            if(s.compare(maxString) > 0)
                maxString = s;

            findMaximum(s, k, index + 1);

            //backtracking
            swap(s[index], s[i]);
        }
    }
}

int main(){
    string s = "7599";
    int k = 2;

    maxString = s;

    findMaximum(s, k, 0);

    cout << "Maximum number: " << maxString << endl;
    
    return 0;
}