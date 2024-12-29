#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;


    //Constructor
    Node(int value){
        data = value;
        next = NULL;
    }
};

Node* reverseLinkLinst(Node*& head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head){
    while(head != NULL){
        cout<< head->data <<"-> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = reverseLinkLinst(head);

    printList(head);

    return 0;
}
