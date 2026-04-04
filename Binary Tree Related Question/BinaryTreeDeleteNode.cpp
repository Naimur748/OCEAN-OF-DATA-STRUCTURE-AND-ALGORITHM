#include <bits/stdc++.h>
using namespace std;

//Node structure
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

//find deepest Node
Node* getDeepest(Node* root){
    queue<Node*> q;
    q.push(root);
    Node* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

    }
    return temp;
}

void deleteDeepest(Node* root, Node* target){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //left child check
        if(temp->left){
            if(temp->left == target){
                temp->left = NULL;
                delete target;
                return;
            }else q.push(temp->left);
        }

        //right child check
        if(temp->right){
            if(temp->right == target){
                temp->right = NULL;
                delete target;
                return;
            }else q.push(temp->right);
        }

    }
    

}

//Delete Node function
Node* deleteNode(Node* root, int key){

    if(!root) return NULL;

    queue<Node*> q;
    q.push(root);

    Node* keyNode = NULL;
    Node* temp;

    //find the target node
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == key)
            keyNode = temp;
        
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

    }

    //if find the keyNode
    if(keyNode){
        Node* deepest = getDeepest(root);
        
        //replaceing the value
        keyNode->data = deepest->data;

        //deepest node delete
        deleteDeepest(root, deepest);
    }

    return root;
}

//print function
void printTree(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        
    }
}

int main(){

    //Making tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << "Before Delete: ";
    printTree(root);

    //Deletint
    root = deleteNode(root, 20);

    cout << "\nAfter Delete: ";
    printTree(root);

    return 0;

}