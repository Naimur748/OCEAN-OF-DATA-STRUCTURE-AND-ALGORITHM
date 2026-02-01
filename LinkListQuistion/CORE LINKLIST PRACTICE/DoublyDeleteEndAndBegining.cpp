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

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
};

void deleteAtBegining(Node*& head){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    
    }
        
    Node* temp = head;
    head = temp->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;

    
}

void deleteAtEnd(Node*& head){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    //single node case
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    // Move to last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
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
    fourth->prev =third;

    cout << "Orginal List: ";
    printList(head);

    //Delete at begining
    deleteAtBegining(head);
    cout << "After delete at Begining: ";
    printList(head);

    //Delete at End;
    deleteAtEnd(head);
    cout << "After Delete at End";
    printList(head);

    return 0;
}