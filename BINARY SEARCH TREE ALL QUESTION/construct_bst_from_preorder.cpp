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


Node* insert(Node* root, int value){

    if(root == NULL){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else{

        root->right = insert(root->right, value);
    }

    return root;
}



Node* constructBST(vector<int>& preorder){

    Node* root = NULL;

    for(int i = 0; i < preorder.size(); i++){

        root = insert(root, preorder[i]);
    }

    return root;
}


void preorderPrint(Node* root){
    
    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    preorderPrint(root->left);

    preorderPrint(root->right);


}

void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }

    inorderPrint(root->left);

    cout << root->data << " ";

    inorderPrint(root->right);
}

int main(){

    vector<int> preorder = {40, 30, 35, 80, 10};

    Node* root = constructBST(preorder);

    //preorder print
    preorderPrint(root);

    cout << endl;

    //Inorder print
    cout << "Inorder Traversal:";
    inorderPrint(root);

    cout << endl;

    return 0;
}