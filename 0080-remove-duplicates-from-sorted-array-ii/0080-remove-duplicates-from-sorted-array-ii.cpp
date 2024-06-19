class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
    for(int j = 0; j < nums.size(); j++)
    {
    if(i < 2 || nums[j] > nums[i-2])
    {
    nums[i++] = nums[j];
    }
    }
    return i;
        

    }
};/*
You can think of this as a "two pointers" solution:

one pointer that processes all the numbers - you have to visit each number to check its value, in this case it's his for(int n : nums)
one pointer that keeps track of the number of values that have been added, in this case i or the length of the array so far.
You take advantage of the sorted nature of the array and only add the number/increment the length iff the current number you're visiting is greater than the number at i-2 to avoid more than 1 duplicate*/