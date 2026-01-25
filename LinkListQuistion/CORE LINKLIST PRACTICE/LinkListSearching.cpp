#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

int LinkListSearch(Node*& head, int key){
    Node* current = head;
    int position = 1;

    while(current != NULL){

        if(current->data == key){
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;


}


int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int key = 30;

    int result = LinkListSearch(head, key);

    if(result != -1)
        cout << "Data: "<< key  << " Link list position: " << result << endl;
    else
        cout << "Data" << key << "Not find" << endl;
    

    return 0;

}