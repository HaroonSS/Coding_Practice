class Solution
{
    public:
        void findCombination(int ind, int target, vector<int> &arr, vector<vector< int >> &ans, vector< int > &temp)
        {
            if (ind == arr.size())
            {
                if (target == 0)
                {
                    ans.push_back(temp);
                }
                return;
            }
           	// pick up the element 
            if (arr[ind] <= target)
            {
                temp.push_back(arr[ind]);
                findCombination(ind, target - arr[ind], arr, ans, temp);
                temp.pop_back();
            }
           	// not pick up
            findCombination(ind + 1, target, arr, ans, temp);
        }
    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> temp;
        findCombination(0, target, candidates, ans, temp);
        return ans;
    }
};