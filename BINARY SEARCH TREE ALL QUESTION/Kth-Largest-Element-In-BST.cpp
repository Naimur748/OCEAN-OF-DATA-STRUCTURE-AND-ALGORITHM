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


void KthLargestUtil(Node* root, int k, int& count, int& ans){

    if(root == NULL) return;

    KthLargestUtil(root->right, k, count, ans);

    count++;

    if(count == k){
        ans = root->data;
        return;
    }

    KthLargestUtil(root->left, k, count, ans);
}


//Wrapper function
int KthLargest(Node* root, int k){
    int count = 0;
    int ans = -1;

    KthLargestUtil(root, k, count , ans);

    return ans;
}

int main(){

     /*
        Example BST:
              4
            /   \
           2     9
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);

    int k = 2;

    int result = KthLargest(root, k);

    cout << k << "th largest element is: " << result << endl;

    return 0;
}