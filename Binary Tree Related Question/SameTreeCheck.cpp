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

bool isSameTree(Node* p, Node* q){

    if(p == NULL && q == NULL)
        return true;

    if(p == NULL || q == NULL)
        return false;


    if(p->data != p->data)
        return false;

    return isSameTree(p->left, q->left) && 
            isSameTree(p->right, q->right);
}

int main(){

    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    bool result = isSameTree(p, q);

    if(result)
        cout << "Tree are Same" << endl;
    else
        cout << "Trees are Not Same" << endl;

    return 0;
}