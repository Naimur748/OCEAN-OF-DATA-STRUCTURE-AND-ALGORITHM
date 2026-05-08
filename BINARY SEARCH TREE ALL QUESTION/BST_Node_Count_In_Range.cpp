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

int countNodes(Node* root, int l, int h){

    if(root == NULL)
        return 0;

    if(root->data >= l && root->data <= h){
        return 1
            + countNodes(root->left, l, h);
            + countNodes(root->right, l, h);
    }

    if(root->data < l){
        return countNodes(root->right, l, h);
    }
    else{
        return countNodes(root->left, l, h);
    }
}

int main(){

     /*
            10
           /  \
          5    50
         /    /  \
        1    40  100
    */

        Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(50);

    root->left->left = new Node(1);

    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;

    int ans = countNodes(root, l, h);

    cout << "Count of nodes in range = " << ans << endl;

    return 0;
}