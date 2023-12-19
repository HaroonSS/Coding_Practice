class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> freq_p(26), freq_s(26);
        int pLength = p.size(), sLength = s.size();
        for(auto it:p) 
            freq_p[it-'a']++;

        int low=0;
        vector<int> res;
        for(int high=0; high<sLength; high++)
        {
            freq_s[s[high]-'a']++;
            if((high-low+1==pLength) && (freq_p==freq_s)) // vector compared
                res.push_back(low);

            if(high-low+1 >= pLength)
            {
                freq_s[s[low]-'a']--;
                low++;
            }
        }
        return res;
    }
};