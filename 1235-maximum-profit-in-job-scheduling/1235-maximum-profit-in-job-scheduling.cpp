#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //     int findNext(int cur, int[][] jobs) {
    //     for (int next = cur + 1; next < jobs.length; next++) {
    //         if (jobs[next][0] >= jobs[cur][1]) {
    //             return next;   
    //         }
    //     }
    //     return jobs.size();// this case is handled in recursion and will return 0 profit
    // }
    // Helper function to find the next non-overlapping job
    int findNextJob(const vector<vector<int>>& jobs, int currentIndex) {
        int low = currentIndex + 1, high = jobs.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid][0] >= jobs[currentIndex][1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    // Top-down recursive function with memoization
    int findMaxProfit(int index, const vector<vector<int>>& jobs, vector<int>& dp) {
        if (index >= jobs.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        // Option 1: Skip the current job
        int skip = findMaxProfit(index + 1, jobs, dp);

        // Option 2: Take the current job
        int nextJobIndex = findNextJob(jobs, index);
        int take = jobs[index][2] + findMaxProfit(nextJobIndex, jobs, dp);

        // Store the result in dp and return the maximum of the two options
        return dp[index] = max(skip, take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        // Combine the jobs into a single vector and sort by start time
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        // Initialize memoization array
        vector<int> dp(n, -1);

        // Find the maximum profit starting from the first job
        return findMaxProfit(0, jobs, dp);
    }
};
/*


This function helps find the next job that starts **after or at the end time** of the current job. It ensures no two selected jobs overlap.


#### **Logic**

1. **Binary Search**:
   - The jobs are sorted by their `startTime`. This allows us to use binary search to find the next job that starts at or after the `endTime` of the current job.

2. **Key Conditions**:
   - If `jobs[mid][0] >= jobs[currentIndex][1]`, it means the job at index `mid` starts after the current job ends. So, we move the search range to the **left** (`high = mid - 1`) to find an earlier valid job.
   - If `jobs[mid][0] < jobs[currentIndex][1]`, it means the job at index `mid` overlaps with the current job. We move the search range to the **right** (`low = mid + 1`).

3. **Result**:
   - At the end of the binary search, `low` points to the index of the next non-overlapping job. If no such job exists, `low` will exceed the size of the array, and we handle that in the recursive function.


### **Recursive Function: `findMaxProfit`**

#### **Purpose**
This function calculates the maximum profit starting from a given job using memoization to avoid redundant calculations.

#### **Logic**
1. **Base Case**:
   - If `index >= jobs.size()`, there are no more jobs left, so the profit is `0`.

2. **Memoization**:
   - If we’ve already computed the result for this index (`memo[index] != -1`), return it directly.

3. **Recursive Choices**:
   - **Skip the current job**: Call `findMaxProfit(index + 1, jobs, memo)`.
   - **Take the current job**:
     - Add the profit of the current job (`jobs[index][2]`).
     - Find the next non-overlapping job using `findNextJob`.
     - Add the result of `findMaxProfit(nextJobIndex, jobs, memo)`.

4. **Store and Return**:
   - Store the maximum of the two choices in `memo[index]`.

---

#### **Example Walkthrough**

Using the same jobs:
```plaintext
jobs = [[1, 3, 50], [2, 4, 10], [3, 5, 40], [3, 6, 70]]
```

1. Start at `index = 0` (job `[1, 3, 50]`):
   - **Skip**: Profit = `findMaxProfit(1, jobs, memo)`
   - **Take**:
     - Next job: `findNextJob(0) = 2`
     - Profit = `50 + findMaxProfit(2, jobs, memo)`

2. Compute recursively for other indices.

---

### **Why Use Binary Search?**

- Binary search reduces the time complexity of finding the next non-overlapping job from \(O(n)\) to \(O(\log n)\).
- This is crucial for achieving an efficient \(O(n \log n)\) solution.


### **Time Complexity Analysis**

1. **Sorting Jobs**: \(O(n \log n)\)
2. **Binary Search**: \(O(\log n)\) for each of \(n\) jobs → \(O(n \log n)\)
3. **Recursive Calls**: \(O(n)\) due to memoization.

Overall: \(O(n \log n)\)

### **Space Complexity Analysis**

- Memoization array: \(O(n)\)
- Recursion stack: \(O(n)\)

Overall: \(O(n)\)

*/