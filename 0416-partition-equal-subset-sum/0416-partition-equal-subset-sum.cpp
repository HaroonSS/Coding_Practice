class Solution {
public:
    bool canPartition(vector<int>& arr) {
    int n = arr.size(), totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    if (totSum % 2 == 1)     // If the total sum is odd, it cannot be partitioned into two equal subsets
        return false;
    
        int k = totSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;       // If the target sum is 0, it can be achieved by not selecting any elements

        }

        if (arr[0] <= k)
            dp[0][arr[0]] = true;    // Initialize the first row based on the first element of the array

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                
                bool notTaken = dp[ind - 1][target];// Exclude the current element

                bool taken = false;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]]; // Include the current element if it doesn't exceed the target

                dp[ind][target] = notTaken || taken;
            }
        }
        return dp[n - 1][k];
        
    }
};