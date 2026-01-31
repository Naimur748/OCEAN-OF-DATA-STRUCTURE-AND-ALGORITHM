#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

};

void printList(Node*& head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << "<-->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;

}

void insertAtPosition(Node*& head, int val, int pos){
    Node* newNode = new Node(val);

    //Insert At begining
    if(pos == 1){
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        
        head = newNode;
        return;
    }

    Node* temp = head;

    //Move to (pos-1)th Node
    for(int i = 1; i < pos-1; i++){
        temp = temp->next;
    }

    //Invalid position
    if(temp == NULL){
        cout << "Invalid position\n";
        return;
    }

    //Insert in Middle or end
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    cout << "Print List ";
    printList(head);

    //Insert at position
    insertAtPosition(head, 25, 3);

    cout << "After Insertion at Position";
    printList(head);
}