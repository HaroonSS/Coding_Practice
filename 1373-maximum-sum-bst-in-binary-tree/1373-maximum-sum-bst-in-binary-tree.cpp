class Solution {
public:
    int ans = 0;
    vector<int> dfs(TreeNode* root) {
        if(!root)
            return {INT_MAX, INT_MIN, 0};
        
        vector<int> L = dfs(root->left);
        vector<int> R = dfs(root->right);
        
        int v = root->val;
        
        if(L[1] < v && v < R[0])
        {
            // subtree from root is a BST
            int sum = L[2] + R[2] + v;
            ans = max(ans, sum);
            
            return {min(v, L[0]), max(v, R[1]), sum};
        }
        else
        {
            return {INT_MIN, INT_MAX, 0};
        }
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
/*
From the definition of a BST, we can figure out that we need a recursive solution - in order to find out whether a subtree at a given node is a BST, we first need to find out whether its children are BSTs. Once we know that left and right subtrees of the node are BSTs, we need to check whether left subtree contains only values that are less than the node's value, and right subtree contains values that are greater than the node's value. Because we need multiple different values for each child, we can make our helper function return a structure with all those values. One more piece of inormation that is needed for calculating the max sum of any BST subtree would be the sum of all values in the subtree, and we can return it as part of our helper structure. Note that we can also solve this without isBst field in the structure if we use other fields to make up for it, but I think this way is more intuitive and more readable.

class Solution {
    struct customStruct {
        bool isBST;
        int minVal, maxVal, sum;
    };
    
    customStruct helper(TreeNode *node, int &res) {
        if (!node) {
            return { true, INT_MAX, INT_MIN, 0 };
        }
        customStruct l = helper(node->left, res);
        customStruct r = helper(node->right, res);
        if (l.isBST && r.isBST && l.maxVal < node->val && r.minVal > node->val) {
            int sum = l.sum + r.sum + node->val;
            res = max(res, sum);
            return { true, min(l.minVal, node->val), max(r.maxVal, node->val), sum };
        } else {
            return { false, 0, 0, 0 };
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};*/
