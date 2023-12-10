class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> um;
        
        for(int num: nums){
            um[num]++;
        }
        
        for(auto ele: um){                   
            if(ele.second > n/2 )
                return ele.first;
        }
        
       return -1; 
    }
};