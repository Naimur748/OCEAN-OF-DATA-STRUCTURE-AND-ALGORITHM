#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Floyd’s Cycle Detection Function
bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main() {
    // Hardcoded Linked List
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    // Creating a LOOP
    // 50 -> 30
    head->next->next->next->next->next = head->next->next;

    if (detectLoop(head))
        cout << "Loop Detected ✅" << endl;
    else
        cout << "No Loop ❌" << endl;

    return 0;
}
