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

// Node* prevNode = NULL;

// bool isValidBST(Node* root){

//     if(root == NULL)
//         return true;

//     if(!isValidBST(root->left))
//         return false;

//     if(prevNode != NULL && root->data <= prevNode->data)
//         return false;

//     prevNode = root;

//     return isValidBST(root->right);
// }



/*

void inorder(Node* root, vector<int>& ans){

    if(!root) return;

    idorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);


}


bool isBST(Node* root){
    vector<int> ans;
    inorder(root, ans);

    for(int i=1; i<ans.size(); i++)
    if(ans[i] <= ans[i-1])
    return 0;

    return 1;
}


*/


bool BST(Node* root, int& prev){

    if(!root) return 1;

    bool l = BST(root->left, prev);
    if(l == 0)
    return 0;

    if(root->data <= prev)
    return 0;

    prev = root->data;
    return BST(root->right, prev);
}


bool isBST(Node* root){

    int prev = INT_MIN;
    return BST(root, prev);
}



int main(){

    /*
            5
           / \
          1   7
    */
   //Hardcode Input
   Node* root = new Node(5);
   root->left = new Node(1);
   root->left->right = new Node(7);

   //Function Call
   if(isBST(root)){
    cout << "Valid BST" << endl;
   }else{
    cout << "Invalid BST" << endl;
   }

   return 0;
}