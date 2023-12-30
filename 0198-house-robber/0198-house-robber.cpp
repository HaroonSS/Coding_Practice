class Solution {
public:
    int recUtil(int n, vector<int>& nums, vector<int> &dp){
        dp[0] = nums[0];
        
        for(int ind =1; ind< n; ind++){
        int pick = nums[ind];
            if(ind > 1)
               pick += dp[ind - 2];
        int notPick = dp[ind - 1];
        
        dp[ind] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recUtil(n, nums, dp);

    }
};/* Memoization TC: O(n)- one time solving every subprob, SC: O(n) + O(n) - dp + stack = O(n)
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

    } Recursion TC: O(2^n) caz for every i we have 2 option pick/ notPick so, 2*2*2*2..., SC: O(n) rec stack space
        int recUtil(int ind, vector<int>& nums){
        if(ind == 0)
            return nums[0];
        if(ind < 0)
            return 0;
        
        int pick = nums[ind] + recUtil(ind - 2, nums);
        int notPick = recUtil(ind - 1, nums);
        
        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return recUtil(n-1, nums);

    }
    */