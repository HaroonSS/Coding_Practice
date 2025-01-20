class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); ++i)
        {
            if(path[i] == '/')    
                continue;
            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
			// pop the top element from stack if exists
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
			// push the directory file name to stack
                st.push(temp);
        }
        
		// adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
		// if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};/*
EXPLANATION

Create a Stack of String with following condition.
Iterate the loop till you doesn't reaches the end of string.
If you encounter a "/" then ignore it.
Create a temp String & Iterate the while loop till you doesn't find "/" and append it to temp.
Now check if temp == "." , then ignore it.
If temp == ".." then pop the element from the stack if it exists.
If no of the above 2 matches push temp to stack as you find a valid path.
Check out temp string on basis of above conditions till you doesn't find "/".
Now add all stack elements to result as res = "/" + st.top() + res
If res.size() is 0 then return "/" if no directory or file is present.
At last return res.*/