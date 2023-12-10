class Solution
{
    public:
        bool containsDuplicate(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] == nums[i])
                {
                    return true;
                }
            }
            return false;
        }
};
/*
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set < int>(nums.begin(),nums.end()).size();
    }

          bool containsDuplicate(vector<int>& nums) {
          unordered_map<int,int > mp;
          for(auto i : nums) mp[i]++;
          bool flag = false;
          for(auto i : mp){
              if(i.second >= 2) return true;
          }
          return flag;
      }
*/