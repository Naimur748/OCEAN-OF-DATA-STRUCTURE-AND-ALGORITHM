#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr){}
};

int getLength(Node* head){

    int length = 0;
    while(head != nullptr){
        length++;
        head = head->next;
    }
    return length;
}

Node* getInterSectionNode(Node* head1, Node* head2){

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if(len1 > len2){

        while(diff--){
            head1 = head1->next;
        }

    }else{

        while(diff--){
            head2 = head2->next;
        }

    }


    while(head1 != nullptr && head2 != nullptr){

        if(head1 == head2){
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

int main(){

    //Assign head1 Node
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    //Assign head2 Node
    Node* head2 = new Node(4);
    head2->next = head1->next->next;

    Node* intersection = getInterSectionNode(head1, head2);

    if(intersection){
        cout<<"Intersection is found: "<<intersection->data<<endl;
    }else{
        cout<<"Intersection not found"<<endl;
    }

    return 0;
}