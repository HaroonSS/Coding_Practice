class Solution {
public:
//     int minaDistance(string S1, string S2) {
//     int n = S1.size();
//     int m = S2.size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     // Initialize the first row and column
//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = i;
//     }
//     for (int j = 0; j <= m; j++) {
//         dp[0][j] = j;
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (S1[i - 1] == S2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1];// If the characters match, no additional cost
//             } else {
//                 // Minimum of three choices:
//                 // 1. Replace the character at S1[i-1] with S2[j-1]
//                 // 2. Delete the character at S1[i-1]
//                 // 3. Insert the character at S2[j-1] into S1
//                 dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
//             }
//         }
//     }
//     return dp[n][m];
        
//     }
// };
// int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
//     if (i < 0)
//         return j + 1;
//     if (j < 0)
//         return i + 1;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // If the characters at the current positions match, no operation is needed
//     if (S1[i] == S2[j])
//         return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

//     // Minimum of three choices:
//     // 1. Replace the character at S1[i] with the character at S2[j]
//     // 2. Delete the character at S1[i]
//     // 3. Insert the character at S2[j] into S1
//     else
//         return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
//                                   min(editDistanceUtil(S1, S2, i - 1, j, dp),
//                                       editDistanceUtil(S1, S2, i, j - 1, dp)));
// }

// int editaDistance(string& S1, string& S2) {
//     int n = S1.size();
//     int m = S2.size();

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
// }
// Space optimize
int minDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++) {
        cur[0] = i; // Initialize the first column of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                // If the characters match, no additional cost
                cur[j] = prev[j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    return prev[m];
}
};