class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        string result = "";
        int i =0, n = strs.size();
        while(strs[0][i] && strs[0][i] == strs[n-1][i]){
            result.push_back(strs[0][i]);
            i++;
        }
        
        return result;
        
    }
};