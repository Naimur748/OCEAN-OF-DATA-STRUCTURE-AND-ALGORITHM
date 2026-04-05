#include <bits/stdc++.h>
using namespace std;

//making Node structure
struct Node{
    int data; 
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool searchNode(Node* root, int key){

    //if Node is NULL
    if(!root) return false;

    //if value is found
    if(root->data == key) return true;

    //search left right from root
    return searchNode(root->left, key) || 
           searchNode(root->right, key);
}

int main(){

    //making tree
    Node* root = new Node(10);
    root->left  = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    int key = 40;
    
    //search result
    if(searchNode(root, key))
        cout << "Found\n";
    else
        cout << "Not found\n";
    
    return 0;
}