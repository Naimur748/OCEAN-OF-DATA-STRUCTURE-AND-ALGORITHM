#include <bits/stdc++.h>
using namespace std;

//making Node structure
struct Node{
    int data;
    Node* left;
    Node* right;

    //create constructor
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){

    Node* root = new Node(10);

    //Making left child from root
    root->left = new Node(20);

    //making right child from root
    root->right = new Node(30);

    //making left subtree
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    //show the output
    cout << "Root: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;

    return 0;

}