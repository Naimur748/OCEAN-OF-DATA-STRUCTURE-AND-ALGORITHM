#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//function for size of tree
int sizeOfTree(Node* root){

    //if Node is NULL size will be zero
    if(root == NULL) return 0;

    return sizeOfTree(root->left) + sizeOfTree(root->right) + 1;

}

int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << "Size of tree: " << sizeOfTree(root) << endl;

    return 0;
}