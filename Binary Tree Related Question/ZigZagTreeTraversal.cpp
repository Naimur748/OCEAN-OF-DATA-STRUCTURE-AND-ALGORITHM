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

vector<int>zigzagTraversal(Node* root){

    vector<int> result;
    if(root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();

        vector<int> level(size);

        for(int i = 0; i < size; i++){

            Node* node = q.front();
            q.pop();

            int index;
            if(leftToRight == true){
                index = i;
            }else{
                index = size - 1 - i;
            }

            level[index] = node->data;

            if(node->left != NULL){
                q.push(node->left);
            }

            if(node->right != NULL){
                q.push(node->right);
            }
        }

        for(int val : level){
            result.push_back(val);
        }

        leftToRight = !leftToRight;

    }

    return result;
}

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = zigzagTraversal(root);

    cout << "ZigZag Traversal: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;

}