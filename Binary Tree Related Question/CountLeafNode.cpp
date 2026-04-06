#include <bits/stdc++.h>
using namespace std;

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

int countLeaf(Node* root){

    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) 
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);

}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Leaf Node: " << countLeaf(root);

    return 0;

}