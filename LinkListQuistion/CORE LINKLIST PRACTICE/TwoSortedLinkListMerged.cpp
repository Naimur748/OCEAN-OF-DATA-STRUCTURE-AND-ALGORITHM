#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* mergetSortedList(Node*& a, Node*& b){
    
    //Dummy node (act as fake head)
    Node dummy(0);
    Node* tail = &dummy;

    //Merge while both list have node
    while(a != nullptr && b != nullptr){
        
        if(a->data < b->data){
            tail->next = a;
            a = a->next;
        }else{
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }
}
int main(){
     // Hardcoded sorted list A
    Node* a = new Node(10);
    a->next = new Node(30);
    a->next->next = new Node(50);

    // Hardcoded sorted list B
    Node* b = new Node(20);
    b->next = new Node(40);
    b->next->next = new Node(60);

    cout << "List A: ";
    printList(a);

    cout << "List B: ";
    printList(b);

    Node* merged = mergeSortedList(a, b);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}