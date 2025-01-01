#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

void printList(Node* head){

    while(head != nullptr){
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;

}

void sortList(Node* head){

    int count[3] = {0, 0, 0};

    Node* temp = head;
    while(temp != nullptr){
        count[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;
    while(temp != nullptr){

        if(count[i] == 0){
            i++;
        }else{
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }

    }
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

     cout << "Original list: ";
    printList(head);

   
    sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}