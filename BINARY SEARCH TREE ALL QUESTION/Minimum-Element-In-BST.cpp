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

int findMinimum(Node* root){

    if(root == NULL){
        return -1;
    }

    Node* current = root;

    while(current->left != NULL) {
        current = current->left;
    }

    return current->data;
}

int main(){

     /*
        Hardcoded BST তৈরি করছি:

                5
               / \
              4   6
             /
            3
           /
          1
    */

    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);

    root->left->left = new Node(3);
    root->left->left->left = new Node(1);

    root->right->right = new Node(7);

    //Find the minimum value
    int minValue = findMinimum(root);

    //output print
    cout << "Minimum value is BST; " << minValue << endl;

    return 0;

}