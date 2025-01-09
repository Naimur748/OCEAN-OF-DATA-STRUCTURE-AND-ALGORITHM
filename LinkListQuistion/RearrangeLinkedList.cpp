#include <iostream>
using namespace std;

//https://chatgpt.com/c/677fe90e-3d24-800e-a82b-469c6e3aea59

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr){}
};

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* current = head;

    while(current){

        Node* nextNode = current->next;
        current->next = prev;

        prev = current;
        current = nextNode;
    }
    return prev;

}

Node* rearrangeList(Node* head){

    if(!head || !head->next) return head;

    Node* middle = findMiddle(head);
    Node* secondHalf = middle->next;
    middle->next = nullptr;

    secondHalf = reverseList(secondHalf);

    Node* firstHalf = head;

    while(secondHalf){
        Node* temp1 = firstHalf->next;
        Node* temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }


}

void printList(Node* head){
   
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout<<"First link list: ";
    printList(head);


    rearrangeList(head);

    cout<<"After rearrange Link list: ";
    printList(head);

    return 0;
    
}