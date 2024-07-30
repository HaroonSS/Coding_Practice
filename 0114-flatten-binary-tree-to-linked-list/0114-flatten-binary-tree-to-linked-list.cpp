class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;
        while (curr != NULL) {
            
            if (curr->left) {               // Check if the current node has a left child
                
                TreeNode* pre = curr->left;  // If yes, find the rightmost node in the left subtree
                while (pre->right) {
                    pre = pre->right;
                }

                pre->right = curr->right;  // Connect the rightmost node in the left subtree to the current node's right child

                curr->right = curr->left;  // Move the entire left subtree to the right child of the current node

                curr->left = NULL;        // Set the left child of the current node to NULL
            }
            curr = curr->right;           // Move to the next node on the right side
        }
    }
};/*
Step 1: Start with the current node as the root of the tree.

Step 2: While the current node is not null we traverse the tree in a while loop:

If the current node has a left child:
Find the rightmost node in the left subtree.
Connect the rightmost node of the left subtree to the current node’s right child.
Update the current node’s right child to be its left child.
Set the current node’s left child to null.
Move to the current node’s right child.
If the current node has no right child:
Move to the current node’s left child (if it exists) or null.
Step 3: Repeat until all nodes are processed.*/