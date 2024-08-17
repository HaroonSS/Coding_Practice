class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Initialize DP and prev arrays
        vector<int> dp(n, 1);    // dp[i] will store the size of the largest subset ending at nums[i]
        vector<int> prev(n, -1); // prev[i] will store the index of the previous element in the subset

        int maxSize = 1, maxIndex = 0;

        // Step 3: Fill the DP and prev arrays
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            // Keep track of the index of the maximum element
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Step 4: Reconstruct the largest divisible subset
        vector<int> largestSubset;

        // Start from the maxIndex and trace back using the prev array
        while (maxIndex >= 0) {
            largestSubset.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        // The subset is reconstructed in reverse order, so reverse it back
        reverse(largestSubset.begin(), largestSubset.end());

        return largestSubset;
    }
};
