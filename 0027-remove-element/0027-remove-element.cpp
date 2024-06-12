class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    
        /*
        vector<int> temp;
        
        
        for (auto i : nums){
            if(i != val){
                temp.push_back(i);
            }
        }
        int k= temp.size();
        for(int i = 0; i< k; i++){
            nums[i] = temp[i];
        }
        
        return k;*/
        
    }
};