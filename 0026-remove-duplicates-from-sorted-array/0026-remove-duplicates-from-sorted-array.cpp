class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int index =0, n= nums.size();
        for(int i=0; i< n-1;i++){
            if(nums[i] != nums[i+1]){
                nums[index++] = nums[i];
            }
        }
        nums[index++] = nums[n-1];
        
        
        return index;
        
    }
};