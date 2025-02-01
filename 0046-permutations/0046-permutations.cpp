class Solution {
public:
    void permute(vector<int>& nums, int left, int right, vector<vector<int>>& ans) {
        if (left == right) {
            // Base case: print when all positions are filled
            ans.push_back(nums);
            return;
        }

        for (int i = left; i <= right; i++) {
            swap(nums[left], nums[i]); // Swap current character with `i`
            permute(nums, left + 1, right, ans);  // Recursive call for next position
            swap(nums[left], nums[i]); // Backtrack to restore original order
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};/*

Printing All Permutations Using Backtracking in C++
Backtracking is an efficient way to generate all permutations of a given string.

Approach
Use recursion to generate permutations.
Swap characters at each position to explore different orderings.
Backtrack by undoing swaps to explore new branches of recursion.
Algorithm
If the current index reaches the end of the string, print the permutation.
Loop through the string from the current index to the end:
Swap the current index with each subsequent index.
Recursively call the function for the next index.
Swap back (backtrack) to restore the original state.

Time Complexity
There are n! (factorial) permutations, where n is the length of the string.
Each recursive call swaps characters and explores new possibilities.
Overall complexity: O(n * n!) (since we do O(n) operations for each permutation).*/
