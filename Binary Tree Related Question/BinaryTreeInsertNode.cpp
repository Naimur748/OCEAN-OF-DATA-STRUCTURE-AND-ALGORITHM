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

//Insert function (level Order)
Node* insertNode(Node* root, int key){

    //if tree is empty
    if(root == NULL) return new Node(key);

    //making queue for bfs
    queue<Node*> q;
    q.push(root);

    //unless queue is empty
    while(!q.empty()){

        //Dequeue the front node from the queue
        Node* temp = q.front();
        q.pop();

        //if left node is blank -> insert
        if(!temp->left){
            temp->left = new Node(key);
            return root;
        }else{
            q.push(temp->left);
        }

        //if the right is blank -> insert
        if(!temp->right){
            temp->right = new Node(key);
            return root;
        }else{
            q.push(temp->right);
        }
    }

    return root;
}

//Tree print (level Order)
void printTree(Node* root){

    //making queue
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    cout << "Before Insert: ";
    printTree(root);

    //Insertion
    root = insertNode(root, 40);

    cout << "\nAfter Insertion: ";
    printTree(root);

    return 0;

}