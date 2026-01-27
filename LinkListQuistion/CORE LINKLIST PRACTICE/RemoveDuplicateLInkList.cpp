#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to remove duplicates from sorted linked list
void removeDuplicates(Node* head) {
   Node* curr = head;

   while(curr != nullptr && curr->next != nullptr){

    if(curr->data == curr->next->data){
        Node* duplicate = curr->next;
        curr->next = curr->next->next;
        delete duplicate;
    }else{
        curr = curr->next;
    }
   }
}

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function (Hardcoded Linked List)
int main() {

    // Creating sorted linked list with duplicates
    Node* head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(40);
    head->next->next->next->next->next->next = new Node(40);

    cout << "Before removing duplicates:\n";
    printList(head);

    removeDuplicates(head);

    cout << "\nAfter removing duplicates:\n";
    printList(head);

    return 0;
}
