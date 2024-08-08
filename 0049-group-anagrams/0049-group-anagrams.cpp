class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> res;
        
        for(string s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            
            um[temp].push_back(s);
        }
        
        for(auto val: um){
            
            res.push_back(val.second);
            
        }
        
        return res;
    }
};