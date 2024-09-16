class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int currSize = q.size();
            double sum = 0;

            for (int i = 0; i < currSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            res.push_back(sum / currSize);
        }

        return res;
    }
};
