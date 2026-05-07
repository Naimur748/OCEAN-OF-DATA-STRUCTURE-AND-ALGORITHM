#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//BST insert function
Node* insert(Node* root, int key){

    if(root == NULL)
        return new Node(key); //Making new node

    if(key < root->data)
        root->left = insert(root->left, key);

    else
        root->right = insert(root->right, key);

    return root;

    
}



int main(){

     /*
        Tree:
              8
             / \
            5   9
           / \
          2   7
         /
        1
    */

    Node* root = NULL;
    vector<int> values = {8, 5, 9, 2, 7, 1};

    //Making BST
    for(int val : values){
        root = insert(root, val);

    }

    //rwsult check
    if(isDeadEnd(root))
        cout << "True (Dead End Exists)" << endl;
    else
        cout << "False (No Dead End)" << endl;

    return 0;
}