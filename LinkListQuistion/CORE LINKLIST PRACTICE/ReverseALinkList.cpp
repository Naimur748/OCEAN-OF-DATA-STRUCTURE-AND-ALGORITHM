#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};


Node* reverseIterative(Node*& head){

    Node* prev = nullptr;
    Node* curr = head;
    Node* next;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {

    // হার্ডকোড লিংকড লিস্ট
    // 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse করা
    head = reverseIterative(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
