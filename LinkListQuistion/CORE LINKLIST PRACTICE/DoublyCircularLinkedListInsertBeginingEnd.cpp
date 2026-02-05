#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

};

void insertAtBegining(Node*& head, int val){

    Node* newNode = new Node();
    newNode->data = val;

    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    head->prev = newNode;
    last->next = newNode;

    head = newNode;
}

void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node();
    newNode->data = val;

    if(head == NULL){
        head->next = newNode;
        newNode->prev = head;
        head = newNode;
        return;
    }

    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;

    head->prev = newNode;
    last->next = newNode;

}

//Traverse Forward
void traverseForward(Node* head){
    if(head == NULL){
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do{
        cout << temp->data << "<->";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

//Traverse Backward
void traverseBackward(Node* head){
    if(head == NULL){
        cout << "List is Empty";
        return;
    }

    Node* last = head->prev;
    Node* temp = last;

    do{
        cout << temp->data << "<->";
        temp = temp->prev;

    }while(temp != last);

    cout << endl;
}
int main(){

    Node* head = NULL;

    insertAtBegining(head, 10);
    insertAtBegining(head, 5);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Travers Forward: ";
    traverseForward(head);

    cout << "Traverse Backward: ";
    traverseBackward(head);

    return 0;
}