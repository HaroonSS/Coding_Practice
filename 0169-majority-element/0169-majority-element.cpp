class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
           int count = 0, candidate = -1;
            for(int num : nums){
                if(count == 0){
                    candidate = num;
                }
                if(candidate == num)
                    count++;
                else
                    count--;
            }          
            return candidate;          
        }
};

/*int n = nums.size();
unordered_map<int, int> um;

for (int num: nums)
{
    um[num]++;
}

for (auto ele: um)
{
    if (ele.second > n / 2)
        return ele.first;
}

return -1;
}*/