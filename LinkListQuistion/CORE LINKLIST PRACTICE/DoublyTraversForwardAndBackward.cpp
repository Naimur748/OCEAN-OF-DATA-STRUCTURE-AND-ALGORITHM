#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// 🔹 Traverse Forward
void traverseForward(Node* head) {
   Node* temp = head;

   cout << "Forward Traversel: ";
   while(temp != NULL){
    cout << temp->data << "<-> ";
    temp = temp->next;
   }
   cout << endl;
}

// 🔹 Traverse Backward
void traverseBackward(Node* head) {

    Node* temp = head;

    //Go to Last Node
    while(temp->next != NULL){
        temp = temp->next;
    }

    cout << "BackWard Traversal: ";
    while(temp != NULL){
        cout << temp->data << "<-> ";
        temp = temp->prev;
    }
    cout << endl;


   
}

int main() {
    // 🔹 Hardcoded Doubly Linked List
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

    // 🔹 Traversals
    traverseForward(head);
    traverseBackward(head);

    return 0;
}
