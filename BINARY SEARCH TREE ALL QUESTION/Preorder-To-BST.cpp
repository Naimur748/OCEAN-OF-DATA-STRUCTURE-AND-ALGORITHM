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

Node* insertBST(Node* root, int key){

    if(root == NULL){
        return new Node(key);
    }

    if(key < root->data){
        root->left = insertBST(root->left, key);
    }else{
        root->right = insertBST(root->right, key);
    }

    return root;


}

void postorder(Node* root, vector<int> &ans){
    if(root == NULL) return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}


int main(){

    vector<int> preorder = {40, 30, 35, 80, 100};

    Node* root = NULL;

    for(int i = 0; i < preorder.size(); i++){
        root = insertBST(root, preorder[i]);
    }

    vector<int> ans;
    postorder(root, ans);

    //output post order Traversal
    cout << "Postorder Traversal: ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}