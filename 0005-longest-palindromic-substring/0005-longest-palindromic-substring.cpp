class Solution {
public:
string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;
    int start = 0;

    // Every single character is a palindrome
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // Check for two-character palindromes
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Expand for longer substrings
    for (int len = 3; len <= n; len++) { // Length of substring
        for (int i = 0; i <= n - len; i++) { // Start index
            int j = i + len - 1; // End index
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}
};/*
Time Complexity: O(n^2): We iterate over all substrings (nested loops).
Space Complexity: O(n^2)Due to the DP table storing results.*/