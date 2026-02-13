#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& st, int element){

    if(st.empty() || st.top() <= element){
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    sortedInsert(st, element);

    st.push(temp);
}

void sortStack(stack<int>& st){

    if(!st.empty()){

        int temp = st.top();
        st.pop();

        sortStack(st);

        sortedInsert(st, temp);
    }
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){

    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Orginal Stack (Top to Bottom)";
    printStack(st);

    

    //Try to stack sort
    sortStack(st);

    cout << "Sort Stack (Top to Bottom): ";
    printStack(st);

    return 0;
}