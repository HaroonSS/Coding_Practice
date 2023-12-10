class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    //The idea is based on Moore’s Voting algorithm.  We first find two candidates. 
    //Then we check if any of these two candidates is actually a majority.
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> output;
        int countMajority = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            if(num2 == element){
                count2++;
            }
        }
        if(count1 > countMajority){
            output.push_back(num1);
        }
        if(count2 > countMajority){
            output.push_back(num2);
        }
        return output;

        
    }
};
/*
        int countMajority = nums.size()/3;
        unordered_map<int, int> map;
        vector<int> output;
        for(auto num : nums){
            map[num]++;
        }
        for(auto num : map){
            if(num.second > countMajority){
                output.push_back(num.first);
            }
        }
        return output;

*/