class Solution {
public:
    int longestPalindrome(string s) {
        
        int countArr[128] = {0};
        int maxLength = 0, oddChar =0;
        
        for(char c : s){
            countArr[c]++;
        }
        
        for(int i=0; i< 128; i++){
            if(countArr[i] % 2 ==0){
                maxLength += countArr[i];
            }
            else if(countArr[i] >= 1){
                maxLength += countArr[i] -1;
                oddChar ++;
            }
        }
        if(oddChar > 0 )
             maxLength ++ ;
       return maxLength; 
    }
};