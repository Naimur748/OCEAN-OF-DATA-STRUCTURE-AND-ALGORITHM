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

int toSumTree(Node* root){

    if(root == NULL ) return 0;

    if(root->left == NULL && root->right == NULL){
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    int leftSum = toSumTree(root->left);

    int rightSum = toSumTree(root->right);

    int oldValue = root->data;

    root->data = leftSum + rightSum;

    return oldValue + root->data;
}


void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);      // left subtree
    cout << root->data << " "; // root print
    inorder(root->right);     // right subtree
}



int main(){

/*          10
          /     \
        -2       6
       /  \     / \
      8   -4   7   5

*/


    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);

    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    toSumTree(root);

    cout << "Inorder of Sum Tree: ";
    inorder(root);

    return 0;
}