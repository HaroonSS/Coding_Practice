class Solution {
public:
  bool ans = false;

bool match(TreeNode * root, TreeNode *subRoot) {
  if (root && subRoot) {
    bool a = match(root -> left, subRoot -> left);
    bool b = match(root -> right, subRoot -> right);

    if ((root -> val == subRoot -> val) && a && b)
      return true;
    else
      return false;
  } else if (!root && !subRoot) 
      return true;
  else 
      return false;
}

void inorder(TreeNode * root, TreeNode * subRoot) {
  if (root) {
    inorder(root -> left, subRoot);
    bool x = match(root, subRoot);
    if (x) ans = 1;
    inorder(root -> right, subRoot);
  }
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorder(root, subRoot);
        return ans;

    }
};/*
Intuition:
In this problem, we can see that all we need to do is to locate the root of the subtree in the tree and then apply a traversal to check whether the two subtrees are equal or not. But that’s not always true. There is nowhere mentioned in the question that identical values cannot exist on the tree. So you need to check for every node whether the two subtrees match. 

Approach:
We need to check for every node whether the subtree beneath it matches the subtree given in the question. For this, we can use inorder traversal to generate all nodes of the given binary tree and then use another function to match the two subtrees. The matching function will be recursive and must have the following conditions:-

If any one of the nodes is null and the other one is not null then we return false.
If both the nodes are null then we need to return true. 
If both the nodes are not null then in that case we need to check for the value of the given two nodes. */