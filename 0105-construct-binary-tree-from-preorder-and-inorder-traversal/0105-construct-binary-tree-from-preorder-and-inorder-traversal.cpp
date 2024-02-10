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
private:
    unordered_map<int, int> findIndex;
    int index = 0;      
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) 
            findIndex[inorder[i]] = i;  
        return build(preorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int start, int end){        
        if(start > end) return NULL;    
        int i = findIndex[preorder[index]];
        TreeNode *tree = new TreeNode(preorder[index++]);
        tree->left  = build(preorder, start, i - 1); 
        tree->right = build(preorder, i + 1, end);   
        return tree;
    }
};