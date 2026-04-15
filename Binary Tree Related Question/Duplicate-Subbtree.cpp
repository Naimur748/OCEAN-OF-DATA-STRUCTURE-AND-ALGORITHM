#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};



unordered_map<string, int> mp;

bool found = false;

string solve(Node* root){

    if(root == NULL) return "#";

    string left = solve(root->left);

    string right = solve(root->right);

    string curr = to_string(root->data) + "," + left + "," + right;

    if(root->left == NULL && root->right == NULL){
        return curr;
    }

    mp[curr]++;

    if(mp[curr] == 2){
        found = true;
    }

    return curr;
}

// main function to check duplicate subtree
int dupSub(Node* root) {
    solve(root);
    return found ? 1 : 0;
}


int main(){

      /*
        Hardcoded Tree:

                1
              /   \
             2     3
            / \     \
           4   5     2
                    / \
                   4   5
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(2);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(5);

    // function callS
    int result = dupSub(root);

    // output print
    cout << "Duplicate Subtree আছে? : " << result << endl;

    return 0;

}