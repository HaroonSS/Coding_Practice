class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            vector<int> unique(256, -1);
            int n = s.size();
            if (n == 0)	
                return 0;

            int max_length = 0;	
            int left = 0, right = 0;
            while (right < n)
            {
                if (unique[s[right]] != -1) //if ele is present the value will be the index of that charecter in the string
                {
                    left = max(unique[s[right]] + 1, left);//left pointer can jump one ele after the previous repeating ele's pos.
                }
                
               	//update the position of the ele in the freq array with the new pointers index in the string.   
                unique[s[right]] = right;
                max_length = max(max_length, right - left + 1);
                right++;	//move right pointer to next ele      
            }
            return max_length;
        }
};
/*
		unordered_set<char> set;
    //Insert, find and erase operations are constant time in C++ unordered_set and unordered_map
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				//If character does exist in the set, ie. it is a repeated character, 
				//we update the left side counter i, and continue with the checking for substring. 
			}
		}
*/