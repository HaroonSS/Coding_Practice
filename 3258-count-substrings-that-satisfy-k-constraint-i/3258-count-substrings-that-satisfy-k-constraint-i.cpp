class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int count = 0;
        
        // Iterate over all starting points of substrings
        for (int i = 0; i < n; i++) {
            int oneCount = 0, zeroCount = 0;
            
            // Iterate over all possible ending points of substrings
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    oneCount++;
                } else {
                    zeroCount++;
                }
                
                // If the substring satisfies the k-constraint, increment count
                if (oneCount <= k || zeroCount <= k) {
                    count++;
                } else {
                    // If the constraint is violated, no need to check further for this starting point
                    break;
                }
            }
        }
        
        return count;
    }
};
