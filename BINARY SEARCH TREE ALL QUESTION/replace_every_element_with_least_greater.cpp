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




int getSuccessor(Node* root, int key){

    int successor = -1;

    while(root != NULL){

        if(root->data > key){

            successor = root->data;
            root = root->left;
        }else{
            root = root->right;
        }
    }

    return successor;
}

//BST Insert function
Node* insert(Node* root, int val){

    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
}



int main(){

    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92,
                       43, 3, 91, 93, 25, 80, 28};

    int n = arr.size();

    Node* root = NULL;

    vector<int> result(n);

    for(int i = n - 1; i >= 0; i--){

        int succ = getSuccessor(root, arr[i]);

        result[i] = succ;

        root = insert(root, arr[i]);
    }

    //output print
    cout << "Output array";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    return 0;
}