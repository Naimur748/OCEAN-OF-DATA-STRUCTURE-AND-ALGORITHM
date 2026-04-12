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

vector<int> bottomView(Node* root){

    vector<int> result;

    if(root == NULL) return result;

    queue<pair<Node*, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while(!q.empty()){

        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int hd = it.second;

        mp[hd] = node->data;

        if(node->left != NULL)
            q.push({node->left, hd - 1});

        if(node->right != NULL)
            q.push({node->right, hd + 1});
    }

    for(auto it : mp){
        result.push_back(it.second);
    }

    return result;


}

int main(){
      /*
        Hardcoded Binary Tree:

                1
               / \
              2   3
             / \   \
            4   5   6
    */

    Node* root = new Node(1);   // root তৈরি
    root->left = new Node(2);   // left child
    root->right = new Node(3);  // right child
    root->left->left = new Node(4); // left subtree
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> ans = bottomView(root); // function call

    cout << "Bottom View: ";
    for (int x : ans) {
        cout << x << " "; // output print
    }

    return 0;
}