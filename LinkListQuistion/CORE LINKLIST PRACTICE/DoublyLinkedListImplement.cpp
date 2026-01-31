#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void printList(Node*& head){
    Node* temp = head;
    while(temp != nullptr){  
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertAtBegining(Node*& head, int val){

    Node* newNode = new Node(val);

    if(head != NULL){
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;

}

void insertAtEnd(Node* head, int val){

    Node* newNode = new Node(val);

    // If List is empty
    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main(){
    //Hardcode Doubly Link List
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printList(head);

    //Insert At Begining
    insertAtBegining(head, 5);
    printList(head);

    insertAtEnd(head, 7);
    printList(head);
    
}