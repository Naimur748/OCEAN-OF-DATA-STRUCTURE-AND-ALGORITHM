#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val = x;
        left = NULL;
        right = NULL;

    }
};

void inorder(Node* root, int k, int &count, int &ans){

    if(root == NULL) return;

    inorder(root->left, k, count, ans);

    count++;

    if(count == k){
        ans = root->val;
        return;
    }

    //visit right subtree
    inorder(root->right, k, count, ans);

}

int kthSmallest(Node* root, int k){

    int count = 0;
    int ans = -1;

    inorder(root, k, count, ans);

    return ans;
}

int main(){

       Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->left->left->left = new Node(1);

    int k = 3; // আমরা 3rd smallest element খুঁজবো

    // function call
    int result = kthSmallest(root, k);

    // output print
    cout << "Kth Smallest Element: " << result << endl;

    return 0;
}