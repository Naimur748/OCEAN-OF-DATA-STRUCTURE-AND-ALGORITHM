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


class Solution{
    public:
        int maxSum = INT_MIN;

        int dfs(TreeNode* root){

            if(root == NULL){
                return 0;
            }

            int left = max(0, dfs(root->left));

            int right = max(0, dfs(root->right));

            int currentPath = left + right + root->val;

            maxSum = max(maxSum, currentPath);

            return root->val + max(left, right);



        }

        maxPathSum(TreeNode* root){

            dfs(root);
            return maxSum;
        }

};



int main(){

      /*
        Hardcoded Tree বানানো হচ্ছে:

                -10
                /  \
               9   20
                  /  \
                 15   7
    */

    TreeNode* root = new TreeNode(-10);   
    root->left = new TreeNode(9);         
    root->right = new TreeNode(20);       
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(7); 

    Solution obj;                         
    int result = obj.maxPathSum(root);    

    cout << "Maximum Path Sum: " << result << endl; 

    return 0;

}