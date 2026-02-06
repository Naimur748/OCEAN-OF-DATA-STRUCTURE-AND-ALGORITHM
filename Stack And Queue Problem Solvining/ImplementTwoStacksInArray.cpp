#include <bits/stdc++.h>
using namespace std;

class twoStacks {
    private:
        int *arr;
        int size;
        int top1, top2;

    public:
        //Constructor
        twoStacks(int n){
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = n;
        }

    //Push to stacks1
    void push1(int x){
        if(top1 + 1 < top2){
            arr[++top1] = x;
        }else{
            cout << "Stacks Overflow in Stacks\n";
        }
    }

    //Push to stack2
    void push2(int x){
        if(top1 + 1 < top2){
            arr[--top2] = x;
        }else{
            cout << "Stack Overflow in Stack\n";
        }
    }
    //Pop From stack1
    int pop1(){
        if(top1 == -1){
            return -1;
        }else{
            return arr[top1--];
        }
    }

    //Pop from stack2
    int pop2(){
        if(top2 == size){
            return -1;
        }else{
            return arr[top2++];

        }
    }


};

int main(){

    twoStacks st(7);

    st.push1(2);
    st.push1(3);
    st.push2(4);

    cout << "pop1(): " << st.pop1() << endl;
    cout << "pop2(): " << st.pop2() << endl;
    cout << "pop2(): " << st.pop2() << endl;

    cout << "--------------------\n";

    twoStacks st2(5);
    
    st2.push1(1);
    st2.push2(2);

    cout << "pop1(): " << st2.pop1() << endl;

    st2.push1(3);

    cout << "pop1(): " << st2.pop1() << endl;
    cout << "pop1(): " << st2.pop1() << endl;

    return 0;


}