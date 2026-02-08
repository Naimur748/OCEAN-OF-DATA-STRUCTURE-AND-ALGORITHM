#include <bits/stdc++.h>
using namespace std;

class Stack{
    deque<int> dq;

    public:
    //Stack push operation
    void push(int x){
        dq.push_back(x);
    }

    void pop(){
        if(dq.empty()){
            cout <<"Stack is Empty\n";
            return;

        }
        dq.pop_back();
    }

    void display(){
        for(int x : dq){
            cout << x << " ";
        }
        cout << endl;
    }

};

//=============Queue Usint Dequeue=================
class Queue{
    deque<int> dq;

    public:

    void enqueue(int x){
        dq.push_back(x);

    }

    void dequeue(){
        if(dq.empty()){
            cout << "Queue is Empty\n";
            return;
        }
        dq.pop_front();
    }

    void display(){
        for(int x : dq){
            cout << x << " ";
        }
        cout << endl;
    }

};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Initial Stack: ";
    st.display();

    st.push(4);
    cout << "After Push(4): ";
    st.display();

    st.pop();
    cout << "After Pop(): ";
    st.display();

    //=======Queue Test =====
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "\nIntial Queue: ";
    q.display();

    q.enqueue(4);
    cout << "After Enqueue(4): ";
    q.display();

    q.dequeue();
    cout << "After Dequeue(): ";
    q.display();

    return 0;
}

