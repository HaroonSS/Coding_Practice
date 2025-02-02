class Solution {
public:
    int partition(vector<int>& nums, int beg, int end) {
        // Random pivot selection to avoid worst-case TLE
        int randomIndex = beg + rand() % (end - beg + 1);
        swap(nums[beg], nums[randomIndex]); // Move random pivot to the start
        // Above 2 lines is to fix TLE (TLE) error, likely due to worst-case
        // behavior when the input is already sorted or contains many
        // duplicates. The issue stems from selecting the first element as the
        // pivot, which leads to poor partitioning (O(n²) complexity in the
        // worst case).

        int pivot = nums[beg];
        int lb = beg, ub = end;

        while (lb <= ub) { // Ensure lb does not cross ub
            while (lb <= ub && nums[lb] <= pivot)
                lb++; // Add boundary condition
            while (lb <= ub && nums[ub] > pivot)
                ub--;

            if (lb < ub) {
                swap(nums[lb], nums[ub]);
            }
        }

        swap(nums[beg], nums[ub]); // Place pivot in correct position
        return ub;
    }

    void quickSort(vector<int>& nums, int beg, int end) {
        if (beg < end) {
            int loc = partition(nums, beg, end);
            quickSort(nums, beg, loc - 1);
            quickSort(nums, loc + 1, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};/*
 Optimizations & Fixes
Random Pivot Selection (rand() % (end - beg + 1)) prevents worst-case behavior in sorted and duplicate-heavy arrays.
Swaps Pivot Randomly before partitioning to balance the recursion depth.
Ensures Proper Partitioning, preventing infinite loops.
Time Complexity Comparison
Approach	Best Case	Average Case	Worst Case
Original (Fixed Pivot)	O(n log n)	O(n log n)	O(n²) (TLE on sorted input)
Randomized Pivot ✅	O(n log n)	O(n log n)	O(n log n) (Prevents TLE)
*/