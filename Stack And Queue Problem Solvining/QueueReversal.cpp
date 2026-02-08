#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> q){

    stack<int> st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    return q;

}

int main(){
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    q = reverseQueue(q);

    cout << "Reverse Queue: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;

}