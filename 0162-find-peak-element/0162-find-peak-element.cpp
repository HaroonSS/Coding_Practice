class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int numsSize = nums.size();
        

        for(int i = 0; i< numsSize; i++){
            if((i > 0 && nums[i] > nums[i-1]) && (i == numsSize-1 ? true :nums[i] > nums[i+1])){
                return i;
            }
        }
        
        return 0;
        
    }
};