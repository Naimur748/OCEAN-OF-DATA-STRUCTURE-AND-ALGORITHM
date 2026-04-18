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

//Recursive function to build tree
Node* buildTree(string s, int &i){

    //if string is finish
    if(i >= s.length()) return NULL;

    //parseing the number
    int num = 0;
    while(i < s.length() && isdigit(s[i])){
        num = num * 10 + (s[i] - '0');
        i++;
    }

    //Making new Node
    Node* root = new Node(num);

    //Left subtree check
    if(i < s.length() && s[i] == '('){
        i++;
        root->left = buildTree(s, i);
    }

    //finish left Subtree ')' skip
    if(i < s.length() && s[i] == ')'){
        i++;
    }

    //Right subtree check
    if(i < s.length() && s[i] == '('){
        i++;
        root->right = buildTree(s, i);
    }

    //Finishing the right subtree ')' skip
    if(i < s.length() && s[i] == ')'){
        i++;
    }

    return root;
}

//Preorder traversal (Root-Left-Right)
void preorder(Node* root){

    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

     // 🔹 Hardcoded input string
    string s = "4(2(3)(1))(6(5))";

    int i = 0; // index pointer

    // Tree build করা
    Node* root = buildTree(s, i);

    // Output (Preorder traversal)
    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;

}