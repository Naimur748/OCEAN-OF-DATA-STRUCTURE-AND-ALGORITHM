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

int checkHeight(Node* root){

    if(root == NULL) return 0;

    int leftHeight = checkHeight(root->left);

    if(leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);

    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}

//main balance check function
bool isBalanced(Node* root){
    return (checkHeight(root) != -1);
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    if(isBalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is Not Balanced" << endl;

    
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    root2->left->left->left = new Node(4);

    if(isBalanced(root2))
        cout << "Tree2 is Balanced" << endl;
    else
        cout << "Tree2 is NOT Balanced" << endl;

    return 0;

}