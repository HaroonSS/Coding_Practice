class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int numsSize = nums.size();
        
        if(numsSize == 1)
            return 0;
        else if(numsSize == 2)
            return nums[0] > nums[1] ? 0 : 1;
        

        for(int i = 0; i< nums.size(); i++){
            if((i > 0 && nums[i] > nums[i-1]) && (i == numsSize-1 ? true :nums[i] > nums[i+1])){
                return i;
            }
        }
        
        return 0;
        
    }
};