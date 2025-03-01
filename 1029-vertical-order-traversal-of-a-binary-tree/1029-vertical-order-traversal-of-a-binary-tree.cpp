class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; // Stores {col -> {row ->[values]}}
        queue<pair<TreeNode*, pair<int, int>>> q; // BFS queue {node, {col, row}}

        q.push({root, {0, 0}}); // Start from root at (0,0)

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first, row = pos.second;

            mp[col][row].insert(node->val); // Store value in map

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> result;
        for (const auto& colData : mp) {
            vector<int> colValues;
            for (const auto& rowData : colData.second)
                colValues.insert(colValues.end(), rowData.second.begin(), rowData.second.end());
            result.push_back(colValues);
        }
        return result;
    }
};
// for (int val : rowData.second) {
//     colValues.push_back(val);
// } equivalent colValues.insert(colValues.end(), rowData.second.begin(), rowData.second.end());
// mp = {
//     {-1, { {1, {9}} }}, 
//     { 0, { {0, {3}}, {2, {15, 7}} }},  
//     { 1, { {1, {20}} }}
// };
// // Sorting Complexity: O(N log N log N log N) (due to nested maps &multiset
// insertions). Overall Complexity: Approximately O(N log N). Space Complexity:
// O(N), storing nodes in a map.
// https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/