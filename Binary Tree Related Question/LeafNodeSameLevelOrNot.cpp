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

bool check(Node* root, int level, int &leafLevel){

    if(root == NULL) return true;

    if(root->left == NULL && root->right == NULL){

        if(leafLevel == -1){
            leafLevel = level;
            return true;
        }
        return (level == leafLevel);
    }

    bool leftCheck = check(root->left, level + 1, leafLevel);

    bool rightCheck = check(root->right, level + 1, leafLevel);

    return leftCheck && rightCheck;
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(10);
    root->left->right = new Node(15);

    int leafLevel = -1;

    //functional call
    bool result = check(root, 0, leafLevel);

    //output print
    if(result)
        cout << "All leaf Nodes are at same leavel(true)" << endl;
    else
        cout << "Leaf nodes are not at same level(false)" << endl;

    return 0;

}