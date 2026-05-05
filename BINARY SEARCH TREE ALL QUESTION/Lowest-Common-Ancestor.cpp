#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }

};

//Functon for find LCA
TreeNode* loweseCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

    while(root != NULL){

        if(p->val < root->val && q->val < root->val){
            root = root->left;
        }
        else if(p->val > root->val && q->val > root->val){
            root = root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
}

int main(){

     // 🔨 Hardcoded BST তৈরি করছি
    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */
   TreeNode* root = new TreeNode(6);
   root->left = new TreeNode(2);
   root->right = new TreeNode(8);

   root->left->left = new TreeNode(0);
   root->left->right = new TreeNode(4);

   root->right->left = new TreeNode(7);
   root->right->right = new TreeNode(9);

   root->left->right->left = new TreeNode(3);
   root->left->right->right = new TreeNode(5);

   //setting P and Q Node
   TreeNode* p = root->left;
   TreeNode* q = root->right;

   //Find the lowest common Ancestor
   TreeNode* lca = lowestCommonAncestor(root, p, q);

   //output print
   if(lca != NULL){
    cout << "Lowest Common Ancestor: " << lca->val << endl;

   }esle{
    cout << "LCA not found" << endl;

   }


   return 0;

   


}