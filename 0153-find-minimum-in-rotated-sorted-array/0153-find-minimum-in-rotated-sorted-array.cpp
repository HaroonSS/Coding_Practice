class Solution {
public:
    int findMin(vector<int>& num) {
        int start=0,end=num.size()-1;    
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return num[start];
    }
};/*
Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array. So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.
---------- start <= end vs start < end
Using start < end and start <= end are just two of the many different ways to implement BS. The key difference is how the search terminates. In case of start <= end, we usually compare mid value to the given target inside the while loop, and terminate early if target is found.

In case of start < end, the loop terminates when start == end.
The start < end method is faster compared to the start <= end (yeah the one that terminates early is actually slower) because in the start <= end case, for every iteration of the while loop, there is that extra if condition which checks mid value to target.

However in the start < end case, this check is done only once when the loop terminates ex: nums[lo] == target or something similar (nums[hi] is also fine) . For this, the cost is 1 extra loop iteration.
*/