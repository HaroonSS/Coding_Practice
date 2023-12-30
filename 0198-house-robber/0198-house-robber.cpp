class Solution {
public:
    int recUtil(int ind, vector<int>& nums, vector<int> &dp){
        if(ind == 0)
            return nums[0];
        if(ind < 0)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int pick = nums[ind] + recUtil(ind - 2, nums, dp);
        int notPick = recUtil(ind - 1, nums, dp);
        
        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recUtil(n-1, nums, dp);

    }
};