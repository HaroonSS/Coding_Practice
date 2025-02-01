class Solution {
public:
    void nextPermutation(vector<int>& s) {
           int n = s.size();
    int i = n - 2;

    // Step 1: Find the rightmost character that is smaller than the next
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }

    if (i >= 0) { // Step 2: Find the rightmost character greater than s[i]
        int j = n - 1;
        while (j >= 0 && s[j] <= s[i]) {
            j--;
        }
        swap(s[i], s[j]); // Step 3: Swap
    }

    // Step 4: Reverse the suffix
    reverse(s.begin() + i + 1, s.end());
        
    }
};