#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k){

    if(k > q.size()){
        return q;
    }

    stack<int> st;

    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    int remaining = q.size() - k;

    for(int i=0; i<remaining; i++){
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    queue<int> result = reverseFirstK(q, k);

    cout << "Resultant Queue: ";
    while(!result.empty()){
        cout << result.front() << " ";
        result.pop();
    }
    return 0;
}