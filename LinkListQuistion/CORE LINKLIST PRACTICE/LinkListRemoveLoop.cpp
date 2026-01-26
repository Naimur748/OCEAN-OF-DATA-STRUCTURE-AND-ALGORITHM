#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void removeLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    //Detect loop using flayed cycle
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(slow != fast) return;

    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Hardcoded linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Remove loop
    removeLoop(head);

    // Print list after removing loop
    printList(head);

    return 0;
}
