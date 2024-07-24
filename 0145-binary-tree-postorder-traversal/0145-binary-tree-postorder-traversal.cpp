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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> st;
        st.push(root);
        st.push(root);
        TreeNode *cur;
        while(!st.empty()){
            cur = st.top();
            st.pop();
            if(!st.empty()&&st.top() == cur){
                if(cur->right) {
                    st.push(cur->right);
                    st.push(cur->right);
                }
                if(cur->left){
                    st.push(cur->left);
                    st.push(cur->left);
                }
            }
            else
                ret.push_back(cur->val);
        }
        return ret; 
    }
};/*
The algorithm is that we push each node twice onto the stack. Each time we pop a node out, if we see that there is a same node on the stack, we know that we have not done traversing yet, and need to keep pushing the current node's children onto the stack. However, if the stack is empty, or the top element is not the same as the current element, we know that we're done searching with this node, thus we can add this node to the result.*/
