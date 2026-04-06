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

int widthOfTree(Node* root){

    if(root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while(!q.empty()){

        int count = q.size();

        maxWidth = max(maxWidth, count);

        while(count--){
            Node* temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

    }
    return maxWidth;

}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Width: " << widthOfTree(root) << endl;

    return 0;

}