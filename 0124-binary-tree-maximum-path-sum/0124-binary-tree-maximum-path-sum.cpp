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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        help(root, sum );
        return sum;
    }
    
    /*** return the max-value-ended-at-root-node ***/
    int help(TreeNode* root,int& sum){
        if(!root)   return 0;
        int left = max(0, help(root->left, sum));
        int right = max(0, help(root->right, sum));
        /*** key parts : embedding the max-value-find in the recursion process ***/
        sum = max(sum, left+right+root->val);
        /*** get the max-value-ended-at-root ***/
        return max(left, right)+root->val;
    }
    
};