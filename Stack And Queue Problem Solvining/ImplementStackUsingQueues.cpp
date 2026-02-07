#include <bits/stdc++.h>
using namespace std;

class Mystack{
    private: 
        queue<int> q1, q2;


    public:
    // constructor
    MyStack(){

    }

    //push operation
    void push(int x){

        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();

        }

        swap(q1, q2);

    }

    int pop(){
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }

};

int main(){

    Mystack myStack;

    myStack.push(1);
    myStack.push(2);

    cout << "Top element: " << myStack.top() << endl;
    cout << "Pop element: " << myStack.pop() << endl;
    cout << "Is stack empty? ";

    if(myStack.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}