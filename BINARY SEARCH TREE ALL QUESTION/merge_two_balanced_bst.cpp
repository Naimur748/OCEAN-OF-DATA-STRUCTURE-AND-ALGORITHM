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


Node* insert(Node* root, int val){

    if(root == NULL)
        return new Node(val);

    if(val < root->data){
        root->left = insert(root->left, val);

    }else{

        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root, vector<int>& arr){

    if(root == NULL){
        return;
    }

    inorder(root->left, arr);

    arr.push_back(root->data);

    inorder(root->right, arr);
}


vector<int> mergeArray(vector<int>& arr1, vector<int>& arr2){

    vector<int> merged;

    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size()){

        if(arr1[i] < arr2[j]){
            merged.push_back(arr1[i]);
            i++;
        }
        else{
            merged.push_back(arr2[j]);
            j++;
        }

    }

    while(i < arr1.size()){
        merged.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()){
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;


}

Node* sortedArrayToBST(vector<int>& arr, int start, int end){

    if(start > end){
        return NULL;
    }

    int mid = (start + end) / 2;

    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);

    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// ================= PREORDER PRINT =================
void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    // root print
    cout << root->data << " ";

    // left subtree
    preorder(root->left);

    // right subtree
    preorder(root->right);
}




Node* mergeBST(Node* root1, Node* root2){

    vector<int> arr1;
    vector<int> arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> mergedArray = mergeArray(arr1, arr2);

    return sortedArrayToBST(mergedArray, 0, mergedArray.size() - 1);

}

int main(){


     // ===== FIRST BST =====
    Node* root1 = NULL;

    // hardcoded input
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);

    // ===== SECOND BST =====
    Node* root2 = NULL;

    // hardcoded input
    root2 = insert(root2, 50);
    root2 = insert(root2, 45);
    root2 = insert(root2, 60);

    // ===== MERGE BST =====
    Node* mergedRoot = mergeBST(root1, root2);

    // ===== OUTPUT =====
    cout << "Preorder Traversal of Merged Balanced BST:\n";

    preorder(mergedRoot);

    return 0;

}