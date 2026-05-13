#include <bits/stdc++.h>
using namespace std;

/* struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info{
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};


int maxBST = 0;

Info solve(Node* root){

    if(root == NULL){
        return {true, 0, INT_MAX, INT_MIN};
    }

    Info leftInfo = solve(root->left);

    Info rightInfo = solve(root->right);

    Info current;

    if(leftInfo.isBST &&
        rightInfo.isBST && 
        leftInfo.maxVal < root->data &&
        root->data < rightInfo.minVal){

            current.isBST = true;

            current.size = 
                leftInfo.size +
                rightInfo.size + 1;

            current.minVal = 
                min(root->data, leftInfo.minVal);

            current.maxVal = 
                max(root->data, rightInfo.maxVal);

            maxBST = max(maxBST, current.size);
        
        }
        else{

            current.isBST = false;

            current.size = 0;

            current.minVal = INT_MIN;
            current.maxVal = INT_MAX;

        }

        return current;

}



int largestBST(Node* root){

    solve(root);

    return maxBST;
}
 */

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

struct Info{
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

int maxBST = 0;

Info solve(Node* root){

    if(root == NULL){
        return {true, 0, INT_MAX, INT_MIN};
    }

    Info leftInfo = solve(root->left);

    Info rightInfo = solve(root->right);

    Info current;

    if(leftInfo.isBST && rightInfo.isBST && 
        leftInfo.maxVal < root->data && root->data < rightInfo.minVal){

            current.size = leftInfo.size +
                            rightInfo.size + 1;

            current.minVal = min(root->data, leftInfo.minVal);

            current.maxVal = max(root->data, rightInfo.maxVal);

            maxBST = max(maxBST, current.size);
        }
        else{

            current.isBST = false;

            current.size = 0;

            current.minVal = INT_MIN;
            current.maxVal = INT_MAX;
        }

        return current;



}




int largestBST(Node* root){

    solve(root);

    return maxBST;
}



int main(){

    /*
            50
           /  \
         30    60
        / \    / \
       5  20  45 70

    Largest BST হবে:

            60
           /  \
          45   70

    Size = 3
    */

    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    int ans = largestBST(root);

    cout << "Largest BST Size = " << ans << endl;

    return 0;
}