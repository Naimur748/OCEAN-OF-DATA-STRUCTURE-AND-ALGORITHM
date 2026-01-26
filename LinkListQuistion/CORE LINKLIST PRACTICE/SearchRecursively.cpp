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

bool recursiveSearch(Node*& head, int key){

    if(head == nullptr) return false;
    if(head->data == key)return true;

    return recursiveSearch(head->next, key);
}



int main(){
    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next= new Node(50);

    int key = 30;

    if(recursiveSearch(head, key))
        cout << key << " Found in the linked list" << endl;
    else
        cout << key << "Not found in the link List " << endl;

    return 0;
}