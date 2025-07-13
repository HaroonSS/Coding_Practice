/**
function invertTree(root) {
  if (!root) return null;
  const queue = [root];
  while (queue.length) {
    const node = queue.shift();
    [node.left, node.right] = [node.right, node.left]; // Swap children
    if (node.left) queue.push(node.left);
    if (node.right) queue.push(node.right);
  }
  return root;
}*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return NULL;
        TreeNode* temp=root->left;   //inorder, preorder, postorder traversal doesn't matter
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};/*
TreeNode* invertTree(TreeNode* root) {
    if(nullptr == root) return root;
    queue<TreeNode*> myQueue;   // our queue to do BFS
    myQueue.push(root);         // push very first item - root

    while(!myQueue.empty()){    // run until there are nodes in the queue         
        TreeNode *node = myQueue.front();  // get element from queue
        myQueue.pop();                     // remove element from queue
                 
        if(node->left != nullptr){         // add left kid to the queue if it exists
            myQueue.push(node->left);
        }
        if(node->right != nullptr){        // add right kid 
            myQueue.push(node->right);
        }       
       swap(node -> left, node -> right);
    }
    return root;
}};*/