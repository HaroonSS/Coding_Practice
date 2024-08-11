class Solution {
public:/*
int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

    if (j < 0 || j >= m)
        return 1e9; 
    if (i == 0)
        return matrix[i][j]; 
    
    if (dp[i][j] != -1)
        return dp[i][j]; 
    
    // Calculate the maximum path sum by considering three possible directions: up, left diagonal, and right diagonal
    int up = matrix[i][j] + getMinUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMinUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMinUtil(i - 1, j + 1, m, matrix, dp);
    

    return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
}
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
     int n = matrix.size(); 
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1)); 
    
    int mini = INT_MAX; 
    
    // Iterate through each cell in the first row to find the minimum path sum starting from each of them
    for (int j = 0; j < m; j++) {
        int ans = getMinUtil(n - 1, j, m, matrix, dp); // Calculate the minimum path sum for the last row
        mini = min(mini, ans); 
    }
    
    return mini; // Return the minimum path sum
    }*/
       int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;

        // Start from the second last row and move upwards
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int down = matrix[i + 1][j]; // directly below
                int leftDiagonal = (j > 0) ? matrix[i + 1][j - 1] : INT_MAX; // diagonal left
                int rightDiagonal = (j < n - 1) ? matrix[i + 1][j + 1] : INT_MAX; // diagonal right

                // Current cell value is updated to include the minimum path sum from the next row
                matrix[i][j] += min(down, min(leftDiagonal, rightDiagonal));
            }
        }

        // The answer will be the minimum value in the first row
        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, matrix[0][j]);
        }

        return mini;
    }
};