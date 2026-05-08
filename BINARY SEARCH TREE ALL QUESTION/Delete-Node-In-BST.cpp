#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* minValueNode(TreeNode* node){
    TreeNode* current = node;

    while(current && current->left != NULL){
        current = current->left;
    }

    return current;
}


TreeNode* deleteNode(TreeNode* root, int key){

    if(root == NULL){
        return NULL;
    }

    if(key < root->val){
        root->left = deleteNode(root->left, key);
    }

    //key is greater than root search right subtree
    else if(key > root->val){
        root->right = deleteNode(root->right, key);

    }
    else{

        if(root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            TreeNode* temp =  root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);

        root->val = temp->val;

        root->right = deleteNode(root->right, temp->val);
    }

    return root;


}

//Inorder Traversal print
void inorder(TreeNode* root){

    if(root == NULL){
        return;

    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}

int main(){

     /*
            5
          /   \
         3     6
        / \     \
       2   4     7
    */

    // Making Hardcoded BST 
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    cout << "Before Delete Inorder Traversal:\n";
    inorder(root);

    cout << endl;

    int key = 3;

    // delete operation
    root = deleteNode(root, key);

    cout << "\n After Delete Inorder Traversal:\n";
    inorder(root);

    cout << endl;

    return 0;
}