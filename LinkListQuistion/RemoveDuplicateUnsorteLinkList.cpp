#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr){}

};

void removeDuplicates(Node* head){

    if(head != nullptr && head->next == nullptr)
    return;


    unordered_set<int> seen;

    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr){

        if(seen.find(current->data) != seen.end()){
            prev->next = current->next;

            delete current;

            current = prev->next;

        }else{

            seen.insert(current->data);
            prev = current;
            current = current->next;

        }

    }

}

void append(Node*& head, int value){

    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(Node* head){
    while(head != nullptr){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;

}



int main(){

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 10);
    append(head, 30);
    append(head, 20);

    cout<<"Link list inncluding duplicate:"<<endl;
    printList(head);

    removeDuplicates(head);

    cout<<"Link list discharge of duplicate"<<endl;
    printList(head);


    return 0;



}