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

int nthFromEnd(Node*& head, int N){

    Node* fast = head;
    Node* slow = head;

    for(int i=0; i<n; i++){
        fast = fast->next;
    }

    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}
int main(){
       Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int N = 2;
    cout << "Nth Node from end is: " << nthFromEnd(head, N);
    return 0;
}