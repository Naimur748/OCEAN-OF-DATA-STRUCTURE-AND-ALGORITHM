#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val ){
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* prevNode = NULL;
Node* head = NULL;

void flattenBST(Node* root){

    if(root == NULL){
        return;
    }

    //first left sub tree visit
    flattenBST(root->left);

    if(prevNode == NULL){
        head = root;
    }
    else{
        prevNode->right = root;
        root->left = NULL;
    }
    prevNode = root;

    flattenBST(root->right);
}

//print after flatten
void printList(Node* root){
    Node* temp = root;

    while(temp != NULL){
        cout << temp->data;

        if(temp->right != NULL){
            cout << "->";
        }

         temp = temp->right;
    }
   
}


int main(){


    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8
    */

    // Making Hardcoded BST
    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // BST flatten করবো
    flattenBST(root);

    // Output print
    cout << "Flattened BST (Sorted Linked List):" << endl;

    printList(head);

    return 0;

}