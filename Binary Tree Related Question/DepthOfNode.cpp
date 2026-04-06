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

int depthOfNode(Node* root, int key, int depth = 0){

    if(root == NULL) return -1;

    if(root->data == key) return depth;

    int left = depthOfNode(root->left, key, depth + 1);

    if(left != -1) return left;

    return depthOfNode(root->right, key, depth + 1);

}


int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << "Depth of 7: " << depthOfNode(root, 7) << endl;

    return 0;


}