#include <bits/stdc++.h>
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

// Palindrome check function
bool isPalindrome(Node* head) {
    //Find Middle
    Node* fast = head;
    Node* slow = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse middle half
    Node* prev = nullptr;
    Node* curr = slow;

    while(curr){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    //Compare two Node palindrome or Not
    Node* left = head;
    Node* right = prev;
    while(right){
        if(left->data != right->data) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Hardcoded linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << "Linked List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "Palindrome Linked List\n";
    else
        cout << "Not a Palindrome Linked List\n";

    return 0;
}
