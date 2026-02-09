#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class MyStack{
    Node* head;
    Node* mid;
    int count;
    
    public:
        MyStack(){
            head = NULL;
            mid = NULL;
            count = 0;
        }
    
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = head;

        if(head != NULL){
            head->prev = newNode;
        }

        head = newNode;
        count++;

        if(count == 1){
            mid = newNode;
        }else if(count % 2 == 0){
            mid = mid->prev;
        }
    }

    int pop(){

        if(count == 0){
            cout << "Stack is empty\n";
            return -1;
        }

        Node* temp = head;
        int item = temp->data;

        head =  head->next;

        if(head != NULL)
            head->prev = NULL;

        count--;

        if(count % 2 == 1 && mid != NULL){
            mid = mid->next;
        }
        delete temp;
        return item;
        
    }

    int findMiddle(){
        if(count == 0){
            cout << "Stack is empty\n";
            return -1;
        }

        return mid->data;
    }

    //Middle element delete
    void deleteMiddle(){
        if(count == 0) return;

        Node* temp = mid;

        if(mid->prev != NULL)
            mid->prev->next = mid->next;
        
        if(mid->next != NULL)
            mid->next->prev = mid->prev;

        if(mid == head)
            head = mid->next;
        
        count--;

        //Mid update
        if(count == 0)
            mid = NULL;
        else if (count % 2 == 0)
            mid = temp->prev;
        else
            mid = temp->next;

        delete temp;
    }
};

int main(){
    MyStack st;

    st.push(1);
    st.push(2);

    cout << st.findMiddle() << " ";
    cout << st.pop() << " ";
    st.deleteMiddle();

    return 0;
}