class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int lis[n];
 
    lis[0] = 1;
 
    // Compute optimized LIS values in
    // bottom up manner
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    // Return maximum value in lis[]
    int res = *max_element(lis, lis + n);
        return res;
    // int mx = res;
    // vector<int>lisList;
    //     for(int i = n-1;i>=0;--i){
    //         if(lis[i] == mx){
    //             lisList.push_back(nums[i]);
    //             mx--;
    //         }
    //     }
    // reverse(lisList.begin(), lisList.end());
    // return lisList;
    }
};/*
 the res will be storing the longest increasing subsequence(LIS), store it in a mx variable, and declare a list lis, Iterate over dp from n-1 to 0. If dp[I[ == nx then it's the LIS and store the v[I] in lis vector and decrease mx. Now m-1 will be the prev element which was the part of LIS and store it in lis vector and decrease mx. Do this and finally reverse the list*/