#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;   // DLL এ prev হিসেবে কাজ করবে
    Node* right;  // DLL এ next হিসেবে কাজ করবে

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


//Global pointer
Node* prevNode = NULL;
Node* head = NULL;

//Inorder Traversal BT -> DLL conversion
void convertToDLL(Node* root){
    if(root == NULL) return;

    //Left subtree visit
    convertToDLL(root->left);

    //current node process
    if(prevNode == NULL){
        head = root;

    }else{
        prevNode->right = root;

        root->left = prevNode;
    }

    prevNode = root;

    convertToDLL(root->right);
}

//DLL print function
void printDLL (Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data;

        if(temp->right != NULL){
            cout << "<=>";
        }

        temp = temp->right;
    }
    cout << endl;
}

int main(){

      /*
        Hardcoded Tree:
               10
              /  \
            20    30
           /  \
         40    60

        Inorder: 40 20 60 10 30
    */

    // Node তৈরি
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // Convert BT to DLL
    convertToDLL(root);

    // Output DLL
    cout << "Doubly Linked List: ";
    printDLL(head);

    return 0;

}