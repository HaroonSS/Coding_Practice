class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; // To store all subsets
        vector<int> current;        // Current subset being constructed
        subsets(nums, 0, current, result);        // Start backtracking from index 0
        return result;
    }

private:
    void subsets(vector<int>& nums, int i, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);          // Add the current subset to the result
        // Explore all elements starting from index i
        for (int j = i; j < nums.size(); j++) {
            current.push_back(nums[j]);         // Include nums[j] in the current subset
            subsets(nums, j + 1, current, result);     // Recurse to generate subsets including nums[j]
            current.pop_back();           // Backtrack to explore subsets without nums[j]
        }
    }
};
/*`nums = [1, 2, 3]`
1. Start with an empty subset: `[]`.
2. Include `1`: `[1]`, recurse for `[2, 3]`.
   - Include `2`: `[1, 2]`, recurse for `[3]`.
     - Include `3`: `[1, 2, 3]`.
     - Backtrack: Remove `3` -> `[1, 2]`.
   - Backtrack: Remove `2` -> `[1]`.
   - Include `3`: `[1, 3]`.
   - Backtrack: Remove `3` -> `[1]`.
3. Backtrack: Remove `1` -> `[]`.
4. Include `2`: `[2]`, recurse for `[3]`.
   - Include `3`: `[2, 3]`.
   - Backtrack: Remove `3` -> `[2]`.
5. Backtrack: Remove `2` -> `[]`.
6. Include `3`: `[3]`.
7. Backtrack: Remove `3` -> `[]`.
#### Output:
`[[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]`

---This method ensures a **systematic exploration of subsets** and runs efficiently with \(O(n * 2^n)\) time complexity.

### **Why This Code Works**
- The `result` vector collects all subsets.
- The recursion explores all combinations of elements starting from a given index.
- Backtracking ensures that all subsets are explored without duplicates by removing the last included element after recursion.
*/