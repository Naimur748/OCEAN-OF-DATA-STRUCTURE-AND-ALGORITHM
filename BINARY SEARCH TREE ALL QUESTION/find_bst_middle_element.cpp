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

//Insert new Node in BST
Node* insert(Node* root, int val){

    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

//Inorder Traversal function
void inorder(Node* root, vector<int>& arr){

    if(root == NULL){
        return;
    }

    inorder(root->left, arr);

    arr.push_back(root->data);

    inorder(root->right, arr);
}

int findMedian(Node* root){
    vector<int> arr;
    inorder(root, arr);

    int n = arr.size();

    //If Node count even
    if(n % 2 == 0){
        return arr[(n/2) - 1];
    }
    else{
        //if Node count Odd
        return arr[n/2];
        
    }


}


int main(){

    Node* root = NULL;

    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 22);

      /*
            12
          /    \
         8      20
        / \    /  \
       4  10  14  22
    */

    // Find the median
    int median =  findMedian(root);
    
    // Output
    cout << "Median of BST = " << median << endl;

    return 0;
}