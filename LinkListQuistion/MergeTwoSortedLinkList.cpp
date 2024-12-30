#include <iostream>
using namespace std;

//https://chatgpt.com/c/67712169-1b0c-800e-89e8-5223e1c0bcb1

struct Node{
    int data;
    Node* next;

    //Constructor or member initializer
    Node(int x) : data(x), next(NULL){};
};

Node* mergedList(Node* L1, Node* L2){

    //Create a dummy node to simplify the merge logic
    Node* dummy = new Node(0);
    Node* current = dummy;

    //Traverse boath list and merge them
    while(L1 != NULL && L2 != NULL){

        if(L1->data < L2->data){
            current->next = L1;
            L1 = L1->next;

        }else{

            current->next = L2;
            L2 = L2->next;
        }

        current = current->next;
    }


    //if any elements are left in either list, append them
    if(L1 != NULL){
        current->next = L1;
    }else{
        current->next = L2;
    }

    //Return the merged list (skip the summy node)
    Node* mergedList = dummy->next;
    delete dummy;
    return mergedList;

}

//Function to prim=nt the list
void printList(Node* head){
    while(head != NULL){
        cout<< head->data<<"->";
        head = head->next;
    }

    cout<<"NULL";
}

int main(){

    //Creatint two sorted link list;
    Node* L1 = new Node(1);
    L1->next = new Node(3);
    L1->next->next = new Node(5);

    Node* L2 = new Node(2);
    L2->next = new Node(4);
    L2->next->next = new Node(6);

   //Merging the two list 
    Node* mergeList = mergedList(L1, L2);


    //Printining the merged list
    cout<<"Merged List in the Bellow: ";
    printList(mergeList);

    return 0;

}