#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteAtPosition(Node*& head, int pos){

    if(head == nullptr) return;

    if(pos == 1){
        Node* temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    Node* curr = head;
    for(int i = 1; i < pos - 1 && curr != nullptr; i++){
        curr = curr->next;

        if(curr == nullptr || curr->next == nullptr) return;

        Node* delNode = curr->next;
        curr->next = delNode->next;
        delete delNode;
    }
}

// Print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){

    // Hardcoded Linked List: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    cout << "Before Deletion: ";
    printList(head);

    // Delete node at position 3 (30 delete হবে)
    deleteAtPosition(head, 3);

    cout << "After Deletion at position 3: ";
    printList(head);

    return 0;
}