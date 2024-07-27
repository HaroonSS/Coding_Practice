/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool pathSumHelper(TreeNode* root, int currentSum, int targetSum){
      if(!root){
            return false;
        }
        
        if(root->left == NULL && root->right == NULL){
            return currentSum + root->val == targetSum;       
        }
        return pathSumHelper(root->left, currentSum + root->val, targetSum) || pathSumHelper(root->right, currentSum + root->val, targetSum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root){
            return false;
        }
        
        return pathSumHelper(root, 0, targetSum);
        
    }
};