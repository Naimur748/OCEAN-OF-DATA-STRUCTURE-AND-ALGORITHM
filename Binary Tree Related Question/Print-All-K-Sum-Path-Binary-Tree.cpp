#include <bits/stdc++.h>
using namespace std;


// Node structure
struct Node {
    int data;          // node এর value
    Node* left;        // left child
    Node* right;       // right child

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void findKSumPaths(Node* root, int k, vector<int>& path){

    if(root == NULL) return;

    path.push_back(root->data);

    int sum = 0;

    for(int i = path.size()-1; i >= 0; i-- ){

        sum += path[i];

        if(sum == k){
            for(int j = i; j < path.size(); j++){
                cout << path[j] << " ";
            }
            cout << endl;
        }
    }

    findKSumPaths(root->left, k, path);

    findKSumPaths(root->right, k, path);

    path.pop_back();
}

int main(){


    // Tree তৈরি করা
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);

    root->left->left = new Node(2);
    root->left->right = new Node(1);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->left->right->left = new Node(1);

    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    root->right->right->right = new Node(6);

    int k = 5;  // target sum

    vector<int> path; // current path store করার জন্য

    // function call
    findKSumPaths(root, k, path);

    return 0;

}