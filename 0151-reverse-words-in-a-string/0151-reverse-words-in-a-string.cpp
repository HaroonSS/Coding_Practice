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
            
            if(result == "") // instead of this if- else block:  result.pop_back();
                result = s.substr(i, j-i);
            else
                result = s.substr(i, j-i) + " " + result;
            
            i = j+1;
            
        }
        
        return result;
        
    }
};