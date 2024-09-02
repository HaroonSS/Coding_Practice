class Solution {
public:
        int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        int mid;
        if(target>nums[high-1]){
            return high;
        }
        while(low<=high){
              mid=(low+high)/2;
            if(nums[mid]==target){  
                return mid;
            }
          
            if(target<nums[mid]){     
            high=mid-1;    
            }else{
            low=mid+1;        
            }
          
        }
         return  low;   
    }
//     int searchInsert(vector<int>& nums, int target) {
//         int left =0, right = nums.size() -1;
        
//         while(left <= right){
//             if(left == right){
//                 return nums[left] >= target ? left > 0 ?left-1: 0 : right+1;
//             }
//             int mid = (left + right)/2;
            
//             if(nums[mid] == target){
//                 return mid;
//             } else if(nums[mid] > target){
//                 right = mid-1;
//             } else {
//                 left = mid+1;
//             }
//         }
//         return left;
//     }
};