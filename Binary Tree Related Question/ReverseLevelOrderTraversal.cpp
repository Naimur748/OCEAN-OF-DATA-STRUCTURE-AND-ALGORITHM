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

void reverseLevelOrder(Node* root){
    
    if(root ==NULL) return;

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while(!q.empty()){

        Node* current = q.front();
        q.pop();

        s.push(current);

        if(current->right != NULL)
           q.push(current->right);
        
        if(current->left != NULL)
            q.push(current->left);

    }

    while(!s.empty()){
        cout << s.top()->data << " ";
        s.pop();
    }
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout << "Reverse Level Order Traversal: ";
    reverseLevelOrder(root);

    return 0;

}