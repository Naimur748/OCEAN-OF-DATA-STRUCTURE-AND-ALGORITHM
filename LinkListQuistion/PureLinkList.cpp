#include <iostream>
using namespace std;

// https://chatgpt.com/c/675f0aba-d944-800e-883c-0d9da743aa7a
struct Node{
    int data;
    Node* next;
};

void append(Node*& head, int value){

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next!= nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }

}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);

    printList(head);

    return 0;
}