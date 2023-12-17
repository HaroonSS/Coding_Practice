class Solution {
public:
    string minWindow(string s, string t) {
    int m[128] = {0};
	// Statistic for count of char in t
	for (auto c : t) m[c]++;
	// counter represents the number of chars of t to be found in s.
	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	size_t size = s.size();
	
	// Move end to find a valid window.
	while (end < size) {
		// If char in s exists in t, decrease counter
		if (m[s[end]] > 0)
			counter--;
		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
		m[s[end]]--;
		end++;
		// When we found a valid window, move start to find smaller window.
		while (counter == 0) {
			if (end - start < minLen) {
				minStart = start;
				minLen = end - start;
			}
			m[s[start]]++;      //s[start] which exist in the target string will become positive. As we skipped the s[i] character so we will increment the counter as we need s[i] later to make a valid window.
			// When char exists in t, increase counter.
			if (m[s[start]] > 0)
				counter++;
			start++;
		}
	}
	if (minLen != INT_MAX)
		return s.substr(minStart, minLen);
	return "";
        
    }
};
/*
The idea is a general solution for substring (longest/shortest/non-duplicated, etc)

Create a hashmap tracking occurences for any specific chars in the target substring
Create two pointers, faster = 0 and slower = 0, to track current width/distance/range of the two pointers. (read below for its usage)
Create a counter tracking if current width/distance/range is a valid substring range
When counter indicates it's a valid range, shrink/expand it's range until range's validity changed(by altering counter accordingly), record down the valid width and let it compare with the last value (using min()/max() accordingly)
*/