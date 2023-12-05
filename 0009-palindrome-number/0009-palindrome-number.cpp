class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0){
            return false;
        }

        long long reverse = 0;
        long long temp = x;

        while (temp != 0) {
            int rem = temp % 10;
            reverse = reverse * 10 + rem;
            temp /= 10;
        }

        return reverse == x;
        
    }
};
