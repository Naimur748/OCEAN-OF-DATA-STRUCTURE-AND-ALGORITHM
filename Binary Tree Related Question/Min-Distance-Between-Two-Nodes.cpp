#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* findLCA(Node* root, int a, int b){

    if(root == NULL) return NULL;

    if(root->data == a || root->data == b)
        return root;

    Node* left = findLCA(root->left, a, b);

    Node* right = findLCA(root->right, a, b);

    if(left != NULL && right != NULL)
        return root;
    
    if(left != NULL) return left;

    return right;

}


int findDistance(Node* root, int target, int dist){

    if(root == NULL) return -1;

    if(root->data == target)
        return dist;

    int left = findDistance(root->left, target, dist + 1);

    if(left != -1) return left;

    return findDistance(root->right, target, dist + 1);
}



int minDistance(Node* root, int a, int b){

    Node* lca = findLCA(root, a, b);

    int d1 = findDistance(lca, a, 0);

    int d2 = findDistance(lca, b, 0);

    return d1 + d2;
}

int main(){

     /*
        Hardcoded Tree:
                11
              /   \
            22     33
           /  \   /  \
         44   55 66  77
    */

    Node* root = new Node(11);
    root->left = new Node(22);
    root->right = new Node(33);
    root->left->left = new Node(44);
    root->left->right = new Node(55);
    root->right->left = new Node(66);
    root->right->right = new Node(77);

    int a = 77;
    int b = 22;

    // ফাংশন কল
    int result = minDistance(root, a, b);

    // আউটপুট দেখাও
    cout << "Minimum Distance: " << result << endl;

    return 0;
}