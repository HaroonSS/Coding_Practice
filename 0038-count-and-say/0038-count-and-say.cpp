class Solution {
public:
    string countAndSay(int n) {
    if (n == 1)      return "1";
    if (n == 2)      return "11";

    // Find n'th term by generating all terms from 3 to n-1.  Every term is generated using previous term
    string str = "11"; // Initialize previous term
    for (int i = 3; i<=n; i++)
    {
        // In below for loop, previous character is processed in current iteration. That 
        //is why a dummy character is added to make sure that loop runs one extra iteration.
        str += '$';
        int len = str.length();

        int cnt = 1; 
        string  tmp = ""; 

        // Process previous term to find the next term
        for (int j = 1; j < len; j++)
        {
            if (str[j] != str[j-1])     
            {
                tmp += to_string(cnt) + str[j-1];   
                cnt = 1;
            }
            else cnt++;       
        }
        str = tmp;
    }
    return str;
    }
};/*
Ans => Whenever we get a character that is unequal to the previous character,we add the previous add our answer for the previous number to the string temp. So for the last number in the string we wont get any inequality and hence it wont get added to string temp. This is why we added a random character at the end so that random character becomes unequal to the last character of the actual string and we could get the desired answer.

Take example "1211".
Here you can not count the last '1'.

But you can in this example "1211$"
if(s[j]==s[j-1]){
cnt++;
}
to count the last one you've to include an ending character.
Time Complexity : O(n^2) 
*/