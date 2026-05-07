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



void storeInorder(Node* root, vector<int>& arr){

    if(root == NULL)
        return;

    storeInorder(root->left, arr);

    arr.push_back(root->data);

    storeInorder(root->right, arr);
}

void arrayToBST(Node* root, vector<int>& arr, int& index){

    if(root == NULL)
        return;

    arrayToBST(root->left, arr, index);

    root->data = arr[index];

    index++;

    arrayToBST(root->right, arr, index);
}




void binaryTreeToBST(Node* root){

    vector<int> arr;

    storeInorder(root, arr);

    sort(arr.begin(), arr.end());

    int index = 0;

    arrayToBST(root, arr, index);
}


void printInorder(Node* root){
    if(root == NULL)
        return;

    printInorder(root->left);

    cout << root->data << " ";

    printInorder(root->right);
}

int main(){

     /*
            Hardcoded Binary Tree

                  8
                 / \
               10   2
              / \
             7   4
    */

    Node* root = new Node(8);

    root->left = new Node(10);
    root->right = new Node(2);

    root->left->left = new Node(7);
    root->left->right = new Node(4);

    cout << "Orginal Tree Inorder: ";
    printInorder(root);

    cout << endl;

    //Binary tree to BST conversion
    binaryTreeToBST(root);

    //BST inorder print 
    cout << "Converted BST Inorder: ";
    printInorder(root);

    cout << endl;

    return 0;

}