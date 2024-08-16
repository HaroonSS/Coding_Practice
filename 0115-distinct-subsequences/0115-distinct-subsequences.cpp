class Solution {
public:
    int countUtil(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        // Base Cases
        if (j < 0) return 1;  // If t is fully matched, return 1
        if (i < 0) return 0;  // If s is exhausted but t is not, return 0

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            dp[i][j] = countUtil(s, t, i - 1, j - 1, dp) + countUtil(s, t, i - 1, j, dp);
        } else {
            dp[i][j] = countUtil(s, t, i - 1, j, dp);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int ls = s.size(), lt = t.size();
        vector<vector<int>> dp(ls, vector<int>(lt, -1));  // Adjust the DP dimensions
        return countUtil(s, t, ls - 1, lt - 1, dp);
    }
};
