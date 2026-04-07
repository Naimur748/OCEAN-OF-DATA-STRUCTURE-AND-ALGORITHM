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

bool isSameTree(TreeNode* s, TreeNode* t){

    if(!s && !t) return true;
    if(!s || !t) false;

    if(s->val != t->val) return false;

    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot){

    if(!root) return false;
    if(isSameTree(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if(isSubtree(root, subRoot))
        cout << "SubTree exists" << endl;
    else
        cout << "SubTree does not exist" << endl;

    return 0;


}