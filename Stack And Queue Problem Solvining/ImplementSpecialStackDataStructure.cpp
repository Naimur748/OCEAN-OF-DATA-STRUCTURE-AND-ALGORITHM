#include<bits/stdc++.h>
using namespace std;

class SpecialStack{
    private:
    stack<int> mainStack;
    stack<int> minStack;
    

    public:
        void push(int x){

            mainStack.push(x);

            if(minStack.empty() || x <= minStack.top()){
                minStack.push(x);
            }
        }

        void pop(){

            if(mainStack.empty()){
                cout << "Stack is Empty\n";
                return;
            }

            int topElement = mainStack.top();
            mainStack.pop();

            if(!minStack.empty() && topElement == minStack.top()){
                minStack.pop();
            }


        }

        int getMin(){
            
            if(minStack.empty()){
                cout << "Stack is Empty";
                return -1;
            }

            return minStack.top();
        }

        bool isEmpty(){
            return mainStack.empty();
        }
};

int main(){

    SpecialStack s;

    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);

    cout << s.getMin() << endl;

    return 0;

}