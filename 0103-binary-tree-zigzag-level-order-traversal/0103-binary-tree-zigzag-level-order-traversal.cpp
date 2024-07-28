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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        vector<vector<int>> res;
        int count = -1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int currSize = q.size();
            vector<int > temp;
            count++;
            
            
            while(currSize--){
                TreeNode* node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
                
            }
            if(count%2 == 1){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);

        }
        
        return res;
    }
};