#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val = x, 
        left = NULL;
        right = NULL;
    }
};


bool searchBST(Node* root, int key){

    if(root == NULL){
        return false;
    }

    if(root->val == key){
        return true;
    }

    if(key < root->val){
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

int main(){
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    root->right->right = new Node(20);

    int key = 7;

    //Functional call
    bool result = searchBST(root, key);

    //output print
    if(result){
        cout << "Tree" << endl;

    }else{
        cout << "False" << endl;
    }

    return 0;

}