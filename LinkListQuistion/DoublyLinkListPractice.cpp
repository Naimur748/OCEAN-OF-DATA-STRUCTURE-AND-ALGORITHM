#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;


    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insert(Node*& head, int val){

  Node* newNode = new Node(val);
  newNode->next = head;

  if(head != NULL){
    head->prev = newNode;
  }
  
  head = newNode;

};

void printList(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){

    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    printList(head);

    return 0;
}