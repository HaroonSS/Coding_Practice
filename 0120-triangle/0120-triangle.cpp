class Solution {
public:/*
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
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
    // Create a 2D DP (dynamic programming) array to store minimum path sums
        int n = triangle.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}
};