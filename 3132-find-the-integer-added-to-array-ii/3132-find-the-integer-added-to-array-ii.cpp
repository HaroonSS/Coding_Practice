class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> nums3 = nums1;
                nums3.erase(nums3.begin() + j);
                nums3.erase(nums3.begin() + i);
                int diff = nums2[0] - nums3[0];
                bool good = 1;
                for (int k = 0; k < n - 2; k++) {
                    if (nums2[k] - nums3[k] != diff) {
                        good = 0;
                        break;
                    }
                }
                if (good) 
                    ans = min(ans, diff);
            }
        }
        return ans;
    }
};