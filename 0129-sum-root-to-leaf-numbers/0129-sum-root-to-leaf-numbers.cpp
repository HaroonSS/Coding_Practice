class Solution {
    void findSum(TreeNode* root, int &sum, int pathSum) {
        if (root == nullptr) return; // Base case
        
        pathSum = pathSum * 10 + root->val; // Correct way to form the number
        
        if (root->left == nullptr && root->right == nullptr) { // Leaf node
            sum += pathSum;
            return;
        }
        
        findSum(root->left, sum, pathSum);
        findSum(root->right, sum, pathSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        findSum(root, sum, 0);
        return sum;
    }
};
