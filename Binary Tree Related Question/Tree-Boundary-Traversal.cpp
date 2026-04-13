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

//function to check left node
bool isLeaf(Node* node){
    return (node->left == NULL && node->right == NULL); 
}

//Addong the left boundary
void addLeftBoundary(Node* root, vector<int>& res){

    Node* curr = root->left;

    while(curr != NULL){

        if(!isLeaf(curr))
            res.push_back(curr->data);
        
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

//Adding Leaf Nodes
void addLeafNodes(Node* root, vector<int>& res){

    if(root == NULL) return;

    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    addLeafNodes(root->left, res);
    addLeafNodes(root->right, res);
}

//Adding Right Boundary
void addRightBoundary(Node* root, vector<int>& res){

    Node* curr = root->right;
    vector<int> temp;

    while(curr != NULL){
        if(!isLeaf(curr))
            temp.push_back(curr->data);
        
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    // reverse order এ result এ add
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root){

    vector<int> res;
    if(root == NULL) return res;

    if(!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeafNodes(root, res);
    addRightBoundary(root, res);

    return res;
}

int main(){

     /*
        Tree structure:
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
              / \
             8   9
    */

    Node* root = new Node(1);   // root create
    root->left = new Node(2);   // left child
    root->right = new Node(3);  // right child

    root->left->left = new Node(4);   // 2 এর left
    root->left->right = new Node(5);  // 2 এর right

    root->right->left = new Node(6);  // 3 এর left
    root->right->right = new Node(7); // 3 এর right

    root->left->right->left = new Node(8);  // 5 এর left
    root->left->right->right = new Node(9); // 5 এর right

    // Boundary Traversal call
    vector<int> result = boundaryTraversal(root);

    // Output print
    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}