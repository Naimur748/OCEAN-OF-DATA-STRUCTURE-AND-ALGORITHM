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

//Top view function
vector<int> topView(Node* root){

    vector<int> result;

    if(root == NULL) return result;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty()){

        auto front = q.front();
        q.pop();

        Node* node = front.first;
        int hd = front.second;

        if(mp.find(hd) == mp.end())
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

    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(90);
    root->right->right = new Node(100);

    //finding top view
    vector<int> ans = topView(root);

    //Output print
    cout << "Top View: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}