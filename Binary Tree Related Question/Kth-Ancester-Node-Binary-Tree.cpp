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


Node* findKthAncestor(Node* root, int &k, int target){

    if(root == NULL)
        return NULL;

    if(root->data == target)
        return root;

    Node* left = findKthAncestor(root->left, k, target);

    Node* right = findKthAncestor(root->right, k, target);

    if(left != NULL || right != NULL){

        k--;

        if(k == 0){

            cout << "Kth Ancestor: " << root->data << endl;
            return NULL;
        }
        return root;
    }
    f
    return NULL;
}


int main(){

    /*
            Hardcoded Binary Tree

                   1
                 /   \
                2     3
               / \
              4   5

        Target = 5
        K = 2
        Expected Output: 1
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int target = 5;

    Node* result = findKthAncestor(root, k, target);

    if(k > 0){
        cout << "kth Ancestor: -1" << endl;
    }

    return 0;
}