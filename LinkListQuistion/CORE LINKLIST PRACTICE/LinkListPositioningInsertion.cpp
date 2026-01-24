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

 void insertAtPosition(Node*& head, int val, int pos){

    if(pos == 1){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    Node* temp = head;

    for(int i = 1; i<pos-1 && temp != nullptr; i++){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
 }

int main(){

    //In built link list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    //Insert position function call
    insertAtPosition(head, 99, 3);

    //Print result

    Node* temp = head;
    while(head != nullptr){
        cout << temp->data <<" -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;



}