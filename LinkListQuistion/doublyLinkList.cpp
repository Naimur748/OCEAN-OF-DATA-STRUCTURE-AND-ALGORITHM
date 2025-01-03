#include <iostream>
using namespace std;

/*

// https://chatgpt.com/c/67610c9a-e0b0-800e-a627-36b04a20874b
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;

    }
};

void inseartAt(Node*& head, int val){
    Node* newNode = new Node(val);

    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<" "<< temp->data <<" "<<"<->";
         temp = temp->next;
    }

    cout<<endl;
}



int main(){

    Node* head = nullptr;

    inseartAt(head, 10);
    inseartAt(head, 20);
    inseartAt(head, 30);


printList(head);
    return 0;
}

*/

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

void insertAtHead(Node*& head, int val){

    Node* newNode = new Node(val);
    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void printList(Node*head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    Node* head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    printList(head);

    return 0;
}
