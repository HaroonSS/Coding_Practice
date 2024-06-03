class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(), i=0;
        
        string result = "";
        
        while(i < n){
            while(i < n && s[i] == ' ')
                i++;
            
            if(i >= n)
                break;
            
            int j=i+1;
            while(j < n && s[j] != ' ')
                j++;
            
            result = s.substr(i, j-i) + " " + result;
            
            i = j+1;
            
        }
        
        result.pop_back();
        
        return result;
        
    }
};