class Solution {
public:
    int partition(vector<int>& nums, int beg, int end) {
        // Random pivot selection to avoid worst-case TLE
        int randomIndex = beg + rand() % (end - beg + 1);
        swap(nums[beg], nums[randomIndex]); // Move random pivot to the start
        
        int pivot = nums[beg];
        int lb = beg, ub = end;

        while (lb <= ub) {  // Ensure lb does not cross ub
            while (lb <= ub && nums[lb] <= pivot) lb++;  // Add boundary condition
            while (lb <= ub && nums[ub] > pivot) ub--;

            if (lb < ub) {
                swap(nums[lb], nums[ub]);
            }
        }

        swap(nums[beg], nums[ub]);  // Place pivot in correct position
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
};