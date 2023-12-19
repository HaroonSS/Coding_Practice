class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq_p(26), freq_s(26);
        for(auto &it:p) freq_p[it-'a']++;

        int low=0;
        vector<int> res;
        for(int high=0; high<s.size(); high++)
        {
            freq_s[s[high]-'a']++;
            if((high-low+1==p.size()) && (freq_p==freq_s)) // vector compared
                res.push_back(low);

            if(high-low+1 >= p.size())
            {
                freq_s[s[low]-'a']--;
                low++;
            }
        }
        return res;
        
    }
};