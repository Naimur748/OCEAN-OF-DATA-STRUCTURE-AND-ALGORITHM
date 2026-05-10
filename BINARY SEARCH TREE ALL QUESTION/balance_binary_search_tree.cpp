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

void inorderTraversal(Node* root, vector<int>& inorder){

  if(root == NULL){
    return;
  }

  inorderTraversal(root->left, inorder);

  inorder.push_back(root->data);

  inorderTraversal(root->right, inorder);
}







Node* buildBalancedBST(vector<int>& inorder, int start, int end){

  if(start > end){
    return NULL;
  }

  int mid = (start + end) / 2;

  Node* root = new Node(inorder[mid]);

  //Making left subtree
  root->left = buildBalancedBST(inorder, start, mid - 1);

  //Making right subtree
  root->right = buildBalancedBST(inorder, mid+1, end);

  return root;


}



Node* balanceBST(Node* root){

  vector<int> inorder;

  inorderTraversal(root, inorder);

  return buildBalancedBST(inorder, 0, inorder.size() - 1);
}





// ------------------------------------------------------
// Inorder Print Function
// ------------------------------------------------------
void printInorder(Node* root)
{
    // যদি NULL হয় তাহলে return
    if(root == NULL)
    {
        return;
    }

    // Left subtree
    printInorder(root->left);

    // Current node print
    cout << root->data << " ";

    // Right subtree
    printInorder(root->right);
}



int main(){


    // Hardcoded Unbalanced BST

    /*
            10
              \
               20
                 \
                  30
                    \
                     40
                       \
                        50
    */

    Node* root = new Node(10);

    root->right = new Node(20);
    root->right->right = new Node(30);
    root->right->right->right = new Node(40);
    root->right->right->right->right = new Node(50);

     // BST Balance করা
    Node* balancedRoot = balanceBST(root);



    // Balanced BST এর inorder print
    cout << "Inorder Traversal of Balanced BST:\n";

    printInorder(balancedRoot);

    cout << endl;

    return 0;

}