
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        findMaxPathSum(root, maxi);
        return maxi;
    }
    
    int findMaxPathSum(TreeNode* root, int &maxi) {
        if (root == nullptr) {
            return 0;
        }
        // Calculate the maximum path sum for the left and right subtrees
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        // Update the overall maximum path sum including the current node
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);

        // Return the maximum sum considering only one branch (either left or right)
        // along with the current node
        return max(leftMaxPath, rightMaxPath) + root->val;
    }
  
};/*
To find the diameter of a binary tree, we can think of every node as a potential `Curving Point` of the path along which we find the sum. The maximum sum of a path through a turning point (like a curve) can be found by adding the maximum sum achievable in the left subtree, the right subtree, and the value of the turning point.
    
We can recursively traverse the tree, considering each node as a potential turning point and storing the maximum value (our final answer) in a reference variable. The recursive function should be defined in such a way that we consider both the possibilities:

When the current node is the turning point and in this scenario we calculate the maximum path sum taking into sum contributions from both the left and right subtrees along with the value of the current node.
When the current node is not the turning point, we consider only the left or the right subtree. The maximum of the two is returned as the maximum path sum of that subtree.
Base Case: When the current node is null which indicates the end of a path or a lead node, we return the maximum path sum=0.

Recursive Function:
Calculate the maximum path sum for the left and right subtrees by making recursive calls to the left and right child of the current node.
Calculate the maximum path sum when the current node serves as the turning point: Maximum Path Sum when Current Node is Turning Point = Maximum Path Sum of Left Subtree + Maximum Path Sum of Right Subtree + Current Value of Node
Update the overall maximum path sum (maxi) by considering the sum of the current node and the left and right subtree sums.
Return the maximum sum considering only one branch (either left or right) along with the value of the current node as the maximum sum up until this node.*/