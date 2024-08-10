class Solution {
public:
    int uniquePathsWithObstaclesUtil(vector<vector<int>>& obstacleGrid, int i,int j, vector<vector<int>> &dp){
        
        
        if(i<0 || j<0 || obstacleGrid[i][j] == 1){
            return 0;
        } else if(i == 0 && j== 0){
            return 1;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = uniquePathsWithObstaclesUtil(obstacleGrid, i-1, j, dp);
        int down = uniquePathsWithObstaclesUtil(obstacleGrid, i, j-1, dp);
        
        return dp[i][j] = up + down;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int >(col, -1));
   
        
        return uniquePathsWithObstaclesUtil(obstacleGrid, row-1, col-1, dp);
        
    }
};