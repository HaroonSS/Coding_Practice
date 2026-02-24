/**
 * @param {number} n
 * @return {number}
 */
// var numTrees = function(n) {
//     let uniqTree = Array(n + 1).fill(1);

//     for (let nodes = 2; nodes <= n; nodes++) {
//         let total = 0;
//         for (let root = 1; root <= nodes; root++) {
//             total += uniqTree[root - 1] * uniqTree[nodes - root];
//         }
//         uniqTree[nodes] = total;
//     }

//     return uniqTree[n];    
// };

    // Function to recursively calculate the number of unique BSTs
    function solve(n, dp) {
        // Base case: If n is 0 or 1, return 1
        if (n <= 1)
            return 1;
        // If the result is already computed, return it
        if (dp[n] !== -1) {
            return dp[n];
        }
        // Initialize answer variable
        let ans = 0;
        // Iterate through all possible roots
        for (let i = 1; i <= n; i++) {
            // Calculate the number of unique BSTs for left and right subtrees
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }
        // Memoize the result and return
        return dp[n] = ans;
    }

    // Function to get the total number of unique BSTs
    function numTrees(n) {
        // Initialize dynamic programming array
        const dp = Array(n + 1).fill(-1);
        // Call the solve function and return the result
        return solve(n, dp);
    }
