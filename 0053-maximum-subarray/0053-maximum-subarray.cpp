class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            int max_so_far = INT_MIN, max_ending_here = 0,
                start = 0, end = 0, s = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                max_ending_here += nums[i];

                if (max_so_far < max_ending_here)
                {
                    max_so_far = max_ending_here;
                    start = s;
                    end = i;
                }

                if (max_ending_here < 0)
                {
                    max_ending_here = 0;
                    s = i + 1;
                }
            }
            return max_so_far;
            
 /*           int ans = INT_MIN, a = 0;
            
            for(int num : nums){
                a += num;
                ans = max(ans, a);
                a = max(a, 0);
            }
            return ans;*/

        }
};
/*
The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous subarray ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so far, Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and update max_so_far if it is greater than max_so_far.

-The subarray with negative sum is discarded (by assigning max_ending_here = 0 in code).
-We carry subarray till it gives positive sum.
*/