#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int index;
    Node* next;

    Node(int x){
        index = x;
        next = NULL;
    }
};

class NStack{
    public:
    //Initialize your data structure
    stack<int> st;
    int* arr;
    Node** Top;

    NStack(int N, int S){

        arr = new int[S];
        Top = new Node*[N];

        for(int i = 0; i < N; i++)
        Top[i] = NULL;

        for(int i = 0; i < S; i++)
        st.push(i);

    }

    //pushes "X" into the Mth stack, Return true if it geets pushed
    bool push(int x, int m){

        if(st.empty())
            return 0;

        arr[st.top()] = x;
        Node* temp = new Node(st.top());
        temp->next = Top[m-1];
        Top[m-1] = temp;
        st.pop();
        return 1;


    }

    int pop(int m){

        if(Top[m-1] == NULL)
            return -1;
        
        int element = arr[Top[m-1]->index];
        st.push(Top[m-1]->index);
        Top[m-1] = Top[m-1]->next;
        return element;

    }

};

int main(){

      int N = 3;  // মোট stack সংখ্যা
    int S = 10; // array size

    NStack ns(N, S);

    // -------- Hardcoded Input --------
    ns.push(10, 1); // stack 1
    ns.push(20, 1);
    ns.push(30, 2); // stack 2
    ns.push(40, 3); // stack 3
    ns.push(50, 2);

    // -------- Output --------
    cout << "Pop from stack 1: " << ns.pop(1) << endl;
    cout << "Pop from stack 2: " << ns.pop(2) << endl;
    cout << "Pop from stack 3: " << ns.pop(3) << endl;

    return 0;

}