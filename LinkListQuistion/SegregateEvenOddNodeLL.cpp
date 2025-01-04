#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;

        }    
};

Node* segregateEvenOdd(Node* head){

    if(!head || !head->next) return head;

    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;
    Node* current = head;

    while(current){

        int val = current->data;

        if(val % 2 == 0){

            if(!evenStart){

                evenStart = current;
                evenEnd = evenStart;

            }else{

                evenEnd->next = current;
                evenEnd = evenEnd->next;

            }
        }else{

            if(!oddStart){

                oddStart = current;
                oddEnd = oddStart;

            }else{

                oddEnd->next = current;
                oddEnd = oddEnd->next;

            }
        } 
        
        current = current->next;
    } 

    if(!evenStart) return oddStart;

    evenEnd->next = oddStart;

    if(oddEnd) oddEnd->next = NULL;

    return evenStart ? evenStart : oddStart;

}

void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Input linked list: 17->15->8->12->10->5->4->1->7->6->NULL
    Node* head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next->next->next = new Node(6);

    cout << "Original Linked List: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}