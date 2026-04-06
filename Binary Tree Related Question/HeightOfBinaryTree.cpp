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

int heightOfTree(Node* root){
    if(root == NULL) return -1;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << "Height of tree: " << heightOfTree(root) << endl;
    return 0;


}