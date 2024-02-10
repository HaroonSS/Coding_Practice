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
    int checkBalance(TreeNode* root, bool &ans){
        if(root == NULL)
            return 0;
        if(!ans) // if Answer is already False then return it.
            return false;
        int leftSubTree = checkBalance(root->left, ans);
        int rightSubTree = checkBalance(root->right, ans);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        bool ans = true;
        checkBalance(root, ans);
        return ans;
    }
};

/*
Start traversing the tree recursively and do work in Post Order.
For each call, caculate the height of the root node, and return it to previous calls.  
Simultaneously, in the Post Order of every node , Check for condition of balance as information of 
left and right subtree height is available.
If it is balanced , simply return height of current node and if not then return false
Whenever the subtree result is false , simply keep on returning false

Time Complexity: O(N) 
Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree)*/