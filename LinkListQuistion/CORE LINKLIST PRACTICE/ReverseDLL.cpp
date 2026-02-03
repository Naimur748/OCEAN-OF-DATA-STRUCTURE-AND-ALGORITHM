#include <bits/stdc++.h>
using namespace std;

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

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 🔴 Reverse Doubly Linked List
void reverseDLL(Node*& head) {
    Node* curr = head;
    Node* temp = NULL;

    // Swap next and prev for all nodes
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if(temp != NULL)
        head = temp->prev;
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

    cout << "Original List: ";
    printList(head);

    reverseDLL(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
