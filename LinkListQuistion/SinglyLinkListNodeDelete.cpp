#include <iostream>
using namespace std;

//Define a Node
struct Node{
    int data;
    Node* next;
};

//function to delete a Node
void deleteNode(Node*& head, int key){
    Node* temp = head;
    Node* prev = nullptr;

    //If head node is a key node
    if(temp != nullptr && temp->data == key){
        head = temp->next;
        delete temp;
        return;
    }

//Processing for deletion 
    while(temp != nullptr && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr){
        cout<<"Key not found in the list."<<endl;
        return;
    }
     
//deletion occured here
    prev->next = temp->next;
    delete temp;
}

void printList(Node* node){
    while(node != nullptr){
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"NULL"<<endl;
}

void push(Node*& head, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

int main(){

    Node* head = nullptr;

    push(head, 40);
    push(head, 30);
    push(head, 20);
    push(head, 10);

    cout<<"Orginal link list: ";
    printList(head);

    deleteNode(head, 20);

    cout<<"Link list after deletion: ";
    printList(head);


    return 0;


}