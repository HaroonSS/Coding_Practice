class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int countArr[26] = {0};
        
        for(char c: s){
            countArr[c - 'a']++;
        }
        for(char c: t){
            countArr[c-'a']--;
        }
        for(int i=0 ; i<26 ; i++){
            if(countArr[i] != 0)
                return false;
        }
        return true;
    }
};