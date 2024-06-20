class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxReach = 0, n = nums.size();
        
        for(int i = 0; i < n; i++){
            
            if(maxReach < i){
                return false;
            }
            
            maxReach = max(maxReach, i+nums[i]);

        }
        return true;
    }
};