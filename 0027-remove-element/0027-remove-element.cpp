class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
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
        
        return k;
        
    }
};