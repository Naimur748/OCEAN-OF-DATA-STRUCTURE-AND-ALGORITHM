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

//Right View function
vector<int> rightView(Node* root){

    vector<int> result;

    if(root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i = 0; i < size; i++){

            Node* curr = q.front();
            q.pop();

            if(i == size-1)
                result.push_back(curr->data);

            if(curr->left != NULL)
                q.push(curr->left);

            if(curr->right != NULL) 
                q.push(curr->right);
        }
    }

    return result;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> ans = rightView(root);

    cout << "Right View: " ;

    //printing the resul
    for(int x : ans){
        cout << x << " ";
    }

    return 0;


}