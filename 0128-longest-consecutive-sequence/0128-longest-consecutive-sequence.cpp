class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxCount = 0;
        
        for(int i =0; i< nums.size(); i++){
            if(s.find(nums[i]-1) == s.end()){
                int j = nums[i], count = 1;
                while(s.find(++j) != s.end()){
                    count++;
                }
                
                maxCount = max(count, maxCount);
            }
        }
         return maxCount;
    }
};