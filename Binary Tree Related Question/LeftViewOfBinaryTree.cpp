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

//Left view function
vector<int> leftView(Node* root){

    vector<int> result;

    if(root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i = 0; i < size; i++){
            Node* current = q.front();
            q.pop();

            if(i == 0){
                result.push_back(current->data);
            }

            if(current->left != NULL){
                q.push(current->left);
            }

            if((current->right != NULL)){
                q.push(current->right);
            }
        }

    }
    return result;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    //Functional call
    vector<int> ans = leftView(root);

    //Output print
    cout << "Left View: ";
    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}