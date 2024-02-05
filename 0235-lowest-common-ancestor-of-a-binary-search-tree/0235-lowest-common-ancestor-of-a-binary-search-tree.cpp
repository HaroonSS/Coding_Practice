/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            // If null, return null as there's no LCA
            return nullptr; 
        }
        
        // Store the value of the current root node
        int curr = root->val;
        
        // If both p and q values are greater
        // than the current root's value
        if (curr < p->val && curr < q->val) {
            // Recursively search in the
            // right subtree for the LCA
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // If both p and q values are smaller
        // than the current root's value
        if (curr > p->val && curr > q->val) {
            // Recursively search in the
            // left subtree for the LCA
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If the values are on either side of the current root's value,
        // or one of the values matches the current root's value,
        // return the current root as the LCA
        return root;
    }
};