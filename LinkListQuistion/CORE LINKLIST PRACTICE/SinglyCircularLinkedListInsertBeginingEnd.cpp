#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
   
   
};

void insertAtBegining(Node*& head, int val){
    Node* newNode = new Node();
    newNode->data = val;

    // If List is Empty
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    //Find the last node
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node();
    newNode->data = val;

    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void traverse(Node* head){

    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do{
        cout << temp->data <<"<->";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

int main(){
    Node* head = NULL;

    insertAtBegining(head, 10);
    insertAtBegining(head, 20);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Singly Circular Linked List: ";
    traverse(head);

    return 0;
}