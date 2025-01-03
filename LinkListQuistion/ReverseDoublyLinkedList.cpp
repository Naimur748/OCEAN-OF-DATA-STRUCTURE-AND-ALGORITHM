//https://chatgpt.com/c/6777d6e4-2b5c-800e-9229-1e5406c28260

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int newData){
        data = newData;
        prev = NULL;
        next = NULL;
    }
};

Node* reverseDoublyLinkedList(Node* head){
    
    Node* tempNode = NULL;
    Node* currentNode = head;

    while(currentNode != NULL){

        tempNode = currentNode->prev; 
        currentNode->prev = currentNode->next;
        currentNode->next = tempNode;

        currentNode = currentNode->prev;
    }

   
    return tempNode->prev;

}

void printList(Node* head){

    Node* tempNode = head;
    while(tempNode != NULL){

        cout<<tempNode->data<<" ";
        tempNode = tempNode->next;
    }
    cout<<endl;
}

void push(Node*& head, int newData){
    Node* newNode = new Node(newData);
    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

int main(){
    Node* head = NULL;

    push(head, 5);
    push(head, 4);
    push(head, 3);

    printList(head);

    head = reverseDoublyLinkedList(head);

    printList(head);

    return 0;
}