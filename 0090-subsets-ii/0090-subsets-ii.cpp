class Solution
{
    void helper(int ind, vector<vector < int>> &res, vector< int > &temp, vector< int > &nums)
    {
        res.push_back(temp);

        for (int i = ind; i < nums.size(); ++i)
        {
            if (i != ind && nums[i] == nums[i - 1]) continue; // remove this line to make it subset sum problem
            temp.push_back(nums[i]);
            helper(i + 1, res, temp, nums);
            temp.pop_back();
        }
    }
    public:
        vector<vector < int>> subsetsWithDup(vector<int> &nums)
        {
            vector<vector < int>> res;
            vector<int> temp;
            sort(nums.begin(), nums.end());
            helper(0, res, temp, nums);
            return res;
        }
};
/*https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/*/