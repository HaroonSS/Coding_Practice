class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        double minAvg = DBL_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i< n/2;i++){
            double a = (nums[i] + nums[n-i-1])/2.0;
            if(a < minAvg)
                minAvg = a;

        }
        
        return minAvg;
        
    }
};