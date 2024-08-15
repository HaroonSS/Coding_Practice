class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        
        string t = s;
        
        reverse(t.begin(), t.end());
        
        vector<vector<int >> dp(n+1, vector<int>(n+1, 0));
        
        for(int i =1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0 + max(dp[i][j-1], dp[i-1][j]);
                }    
            }
        }
        
        int longestPalindromicSubseq = dp[n][n];        
        return n - longestPalindromicSubseq;
    }
};/*
In order to minimize the insertions, we need to find the length of the longest palindromic component or in other words, the longest palindromic subsequence.

Minimum Insertion required = n(length of the string) - length of longest palindromic subsequence.
    
Approach:

We are given a string (say s), store its length as n.
Find the length of the longest palindromic subsequence ( say k) as discussed in dp - 28
Return n-k as answer.*/