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
    }
    
Time Complexity: O(N*N): At max, there will be M*N calls of recursion to solve a new problem,

Space Complexity: O(N) + O(N*M):We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M’.*/
    
    
    
    
    
    
    
       int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the first row of dp with values from the matrix (base condition)
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        // Start from the second last row and move upwards
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                int down = matrix[i][j] + dp[i - 1][j]; // directly below
                int leftDiagonal = (j-1 >= 0) ? matrix[i][j] + dp[i - 1][j - 1] : INT_MAX; // diagonal left
                int rightDiagonal = (j+1 < n) ? matrix[i][j] + dp[i - 1][j + 1]: INT_MAX; // diagonal right

                // Current cell value is updated to include the minimum path sum from the next row
                dp[i][j] += min(down, min(leftDiagonal, rightDiagonal));
            }
        }

        // The answer will be the minimum value in the first row
        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};/*

Time Complexity: O(N*M):There are two nested loops

Space Complexity: O(N*M):We are using an external array of size ‘N*M’. The stack space will be eliminated.*/




    
    
    
    
    
    
    
