class Solution {
public:
/*
1.Express everything(i.e. the given array) in terms of the index.
2.Try all partitions.
3.Return the best possible answer of the two partitions (the answer that comes after dividing the problem into two subproblems and solving them recursively).
*/
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to find the minimum number of partitions to make palindromes.
int minPartitions(int i, int n, string &str, vector<int> &dp) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
    
int minCut(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    return minPartitions(0, n, str, dp) - 1;
    }
};
/*
Time Complexity: O(N2) There are a total of N states and inside each state, a loop of size N is running.
Space Complexity: O(N) + Auxiliary stack space O(N)
  
    
1.First of all, we handle the base case. If (i == n) we return 0. To cover this case we can initialize the entire dp array with 0.
2.Here, as we are checking dp[j+1]  every time, the function will give a runtime error if j= n-1 To avoid this, we will take the array size as n+1 instead of n.
3.Next, memoization is a top-down approach, whereas tabulation is bottom-up. Our changing parameter i will change in opposite directions, i.e i will change from n-1→0.
4.Next, we copy down the recursive logic(recurrence) inside the loop.
    
int palindromePartitioning(string str) {
    int n = str.size();
    // Create a DP array to store the minimum number of partitions.
    vector<int> dp(n + 1, 0);
    dp[n] = 0; // Initialize the last element to 0.

    // Loop through the string in reverse order.
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    // Subtract 1 as it counts partitions, not cuts.
    return dp[0] - 1;
}
int main() {
    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}

Time Complexity: O(N2) There are a total of N states and inside each state a loop of size N(apparently) is running.

Space Complexity: O(N) for the dp array we have used.

*/








