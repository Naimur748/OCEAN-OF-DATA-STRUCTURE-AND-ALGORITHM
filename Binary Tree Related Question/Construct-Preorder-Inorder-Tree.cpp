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


// inorder traversal print করার function (verify করার জন্য)
void printInorder(Node* root) {
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder,
                int preStart,int preEnd,
                int inStart, int inEnd){
    
    //Base case
    if(preStart > preEnd || inStart > inEnd)
      return NULL;

    //first element of preorder is root
    int rootValue = preorder[preStart];
    Node* root = new Node(rootValue);

    //find the root value from inorder
    int rootIndex = inStart;
    for(int i = inStart; i <= inEnd; i++){
        if(inorder[i] == rootValue){
            rootIndex = i;
            break;
        }
    }

    //count left subtree
    int leftSize = rootIndex - inStart;

    //Recursive call for making left subtree
    root->left = buildTree(preorder, inorder,
                             preStart + 1,preStart + leftSize,
                             inStart, rootIndex - 1);


    //Recursive call for making right subtree
    root->right = buildTree(preorder, inorder, 
                            preStart + leftSize + 1, preEnd,
                            rootIndex + 1, inEnd);

    return root;
}

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int n = preorder.size();

    Node* root = buildTree(preorder, inorder, 0, n-1, 0, n-1);

    cout << "Inorder Traversal: ";
    printInorder(root);

    return 0;

}