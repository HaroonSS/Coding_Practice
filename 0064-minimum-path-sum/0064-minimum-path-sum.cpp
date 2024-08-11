class Solution {
public:
    int minPathSumUtil(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        // Base case: if we're at the top-left corner, return its value
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        
        // If we're out of bounds, return a large value (since we want to minimize the sum)
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        // Recursively calculate the minimum path sum by considering the paths from the top and left
        int up = minPathSumUtil(grid, i - 1, j, dp);
        int left = minPathSumUtil(grid, i, j - 1, dp);
        
        // Add the current cell's value to the minimum of the two paths
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        // Start the recursive calculation from the bottom-right corner
        return minPathSumUtil(grid, row - 1, col - 1, dp);
    }
};
