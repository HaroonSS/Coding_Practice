class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for (char c : s) { 
            if (c == '(' || c == '{' || c == '[') { 
                st.push(c); 
            } else { 
                if (st.empty() || // if the stack is empty or 
                    (c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; // the string is not valid, so return false
                }
                st.pop(); // otherwise, pop the opening bracket from the stack
            }
        }
        return st.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
                           // so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }
};