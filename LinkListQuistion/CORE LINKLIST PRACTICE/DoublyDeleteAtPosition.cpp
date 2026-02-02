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

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtPosition(Node*& head, int pos){

    if(head == NULL){
        cout << "Node is empty";
        return;
    }
    
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        
        if(head != nullptr)
            head->prev = NULL;

            delete temp;
            return;
    }

    Node* temp = head;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Invalid Position\n";
        return;
    }

    //Delete Middle or end;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

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
    fourth->prev = third;

    int pos = 3;

    cout << "Before deleting Node List: "; 
    printList(head);
    deleteAtPosition(head, pos);

    cout << "After Deletining Node: ";
    printList(head);

    return 0;

}