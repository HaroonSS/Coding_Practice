class Solution {
public:
    bool isPalindrome(string s) {
        
        string S = "";
        
        for(auto c : s){
            if(c >= 'A' && c <= 'Z')
                S.push_back(c + 32); // c-'A' + 'a'
            else if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                S.push_back(c);
        }
        
        int left = 0, right = S.size() - 1;
        
        while(left < right){
            if(S[left++] != S[right--]){
                return false;
            }
        }
        
        return true;
    }
};