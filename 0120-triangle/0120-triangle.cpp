class Solution {
public:
    int minimumTotalUtil(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>> &dp){
        
        if(i == n){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = minimumTotalUtil(triangle, i+1, j, n, dp);
        int diagonal = minimumTotalUtil(triangle, i+1, j+1, n, dp);
        
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size(), col = triangle[row-1].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        return minimumTotalUtil(triangle, 0, 0, row -1, dp);
    }
};