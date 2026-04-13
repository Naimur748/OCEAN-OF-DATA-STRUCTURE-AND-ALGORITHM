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

vector<int> diagonalTraversal(Node* root){

   
    vector<int> result;

    if(root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        Node* curr  = q.front();
        q.pop();

        while(curr != NULL){
            result.push_back(curr->data);

            if(curr->left != NULL){
                q.push(curr->left);
            }
            curr = curr->right;
        }
    }

    return result;

}

int main(){

     // Hardcoded Binary Tree তৈরি
    /*
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \     /
         4   7   13
    */

     Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

     // Diagonal Traversal call
    vector<int> ans = diagonalTraversal(root);

    // Output print
    cout << "Diagonal Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}