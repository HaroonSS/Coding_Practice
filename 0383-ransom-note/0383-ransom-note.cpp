class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> v(26, 0);
        
        for(char c: ransomNote){
            v[c-'a']++;
        }
        for(char m: magazine){
            v[m-'a']--;
        }
        
        for (auto i: v){
            if(i > 0){
                return false;
            }
        }
        return true;
    }
};