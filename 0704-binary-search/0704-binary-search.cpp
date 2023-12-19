class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, low = 0, high = nums.size() -1;
        
        while(low <= high){
            
            mid = low + (high - low)/2; 
            //C++ int. The int keyword is used to indicate integers. Its size is usually 4 bytes. Meaning, it can store values from -2147483648 to 2147483647.

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
        
    }
};