#include <bits/stdc++.h>
using namespace std;

int main(){

    string stream = "aabc";
    int freq[26] = {0};

    queue<char> q;

    for(char ch : stream){

        freq[ch - 'a']++;
        q.push(ch);

        while(!q.empty()){

            if(freq[q.front() - 'a'] == 1){
                cout << q.front() << " ";
                break;
            }else{
                q.pop();
            }
        }
        if(q.empty()){
            cout << -1 << " ";
        }
    }
    return 0;
}