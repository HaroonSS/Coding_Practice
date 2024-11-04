class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int singleNum = 0;
        
        for (int num: nums){
            singleNum ^= num;
        }
        return singleNum;
    }
};