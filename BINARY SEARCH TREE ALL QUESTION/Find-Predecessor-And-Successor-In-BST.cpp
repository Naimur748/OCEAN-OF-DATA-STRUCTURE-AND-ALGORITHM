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
    if(root == NULL) return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);


    return root;
}


//Find the predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){

    if(root == NULL) return;

    if(root->data == key){

        if(root->left != NULL){
            Node* temp = root->left;

            while(temp->right)
                temp = temp->right;

                pre = temp;
            
        }

        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left)
                temp = temp->left;

                suc = temp;

        }

        return;
    }

    //if key is small
    if(key < root->data){
        suc = root;
        findPreSuc(root->left, pre, suc, key);

    }else{
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}



int main(){
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    for(int i = 0; i < n; i++){
        root = insert(root, arr[i]);
    }

    int key = 65;

    Node* pre = NULL;
    Node* suc = NULL;

    //Functional call
    findPreSuc(root, pre, suc, key);

    cout << "Predecessor:";
    if(pre) cout << pre->data << endl;
    else cout << "NULL" << endl;

    cout << "Successor: ";
    if(suc) cout << suc->data << endl;
    else cout << "NULL" << endl;

    return 0;
}