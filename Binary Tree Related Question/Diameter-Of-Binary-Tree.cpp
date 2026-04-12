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

//function for count height of tree
int height(Node* root){

    if(root == NULL) return -1;

    int left = height(root->left);

    int right = height(root->right);

    return max(left, right) + 1;
}

/*
       1
      / \
     2   3
    / \
   4   5
*/

//Function for finding diameter
int diameter(Node* root){

    if(root == NULL) return 0;

    int leftDia = diameter(root->left);

    int rightDia = diameter(root->right);

    int currentDia = height(root->left) + height(root->right) + 2;

    return max(currentDia, max(leftDia, rightDia));

}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //Print Diameter
    cout << "Diameter: " << diameter(root) << endl;

    return 0;
}