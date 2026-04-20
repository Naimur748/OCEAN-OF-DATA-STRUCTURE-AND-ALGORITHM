#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }

};

class Codec{
    public:

        //Serialize function (Tree -> String)
        string serialize(TreeNode* root){
           
            if(!root) return "";

            queue<TreeNode*> q;
            q.push(root);

            string result = "";

            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();

                if(node == NULL){
                    result += "null,";
                }else{
                    result += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }

            }
            return result;

        }


        //Deserialize function (Strint -> Tree);
        TreeNode* deserialize(string data){

            if(data == "") return NULL;

            stringstream ss(data);
            string item;

            vector<string> nodes;

            while(getline(ss, item, ',')){
                nodes.push_back(item);
            }

            TreeNode* root = new TreeNode(stoi(nodes[0]));
            queue<TreeNode*> q;
            q.push(root);

            int i = 1;
            
            while(!q.empty()){
                TreeNode* parent = q.front();
                q.pop();

                //left child making
                if(nodes[i] != "null"){
                    TreeNode* leftNode = new TreeNode(stoi(nodes[i]));
                    parent->left = leftNode;
                    q.push(leftNode);
                }
                i++;

                //rihgt node making
                if(nodes[i] != "null"){
                    TreeNode* rightNode = new TreeNode(stoi(nodes[i]));
                    parent->right = rightNode;
                    q.push(rightNode);
                }
                i++;
            }

            return  root;

        }
        


};

// 🔹 Tree print (Level Order)
void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
            cout << "null ";
            continue;
        }

        cout << node->val << " ";

        q.push(node->left);
        q.push(node->right);
    }
}

int main(){

     // 🔸 manually tree তৈরি করা
    // Example: [1,2,3,null,null,4,5]

    TreeNode* root = new TreeNode(1);   // root
    root->left = new TreeNode(2);       // left child
    root->right = new TreeNode(3);      // right child

    root->right->left = new TreeNode(4);  // left of 3
    root->right->right = new TreeNode(5); // right of 3

    Codec obj;

    // 🔹 Serialize
    string data = obj.serialize(root);
    cout << "Serialized: " << data << endl;

    // 🔹 Deserialize
    TreeNode* newRoot = obj.deserialize(data);

    // 🔹 Print tree
    cout << "Deserialized Tree: ";
    printTree(newRoot);

    return 0;

}