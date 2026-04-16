#include <bits/stdc++.h>
using namespace std;

// Node structure define করা
struct Node {
    int data;          // node-এর value
    Node* left;        // left child
    Node* right;       // right child

    // constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//LCA function
Node* findLca(Node* root, int n1, int n2){

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    Node* left = findLca(root->left, n1, n2);

    Node* right = findLca(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;
    
    if(left != NULL)
        return left;
    
    return right;
}

int main(){

      /*
        Hardcoded Tree:

                1
              /   \
             2     3
            / \     \
           4   5     7
                    /
                   8
    */

    // Tree তৈরি করা
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    // input values (hardcoded)
    int n1 = 7;
    int n2 = 8;

    // LCA বের করা
    Node* lca = findLca(root, n1, n2);

    // result print করা
    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;

}