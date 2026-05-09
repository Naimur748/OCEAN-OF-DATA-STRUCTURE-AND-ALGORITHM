#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
            next = NULL;
        };

};


Node* prevNode = NULL;

void populateNext(Node* root){

    if(root == NULL){
        return;
    }

    populateNext(root->left);

    if(prevNode != NULL){
        prevNode->next = root;
    }

    prevNode = root;

    populateNext(root->right);
}

void printInorderSuccessor(Node* root){

    if(root == NULL){
        return;
    }

    printInorderSuccessor(root->left);

    cout << root->data << "->";

    if(root->next != NULL){
        cout << root->next->data;
    }else{
        cout << -1;
    }

    cout << endl;

    printInorderSuccessor(root->right);
}


int main(){

    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(12);

    root->left->left = new Node(3);
    
    populateNext(root);

    cout << "Inorder Successor Connections:" << endl;

    printInorderSuccessor(root);

    return 0;

}