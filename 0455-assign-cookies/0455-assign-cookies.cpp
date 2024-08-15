class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int cookiesNums = s.size();
        if(cookiesNums == 0)  return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIndex = 0, childIndex = 0;
        
        while(cookieIndex < s.size() && childIndex < g.size()){
            if(s[cookieIndex] >= g[childIndex]){
                maxNum++;
                cookieIndex++;
                childIndex++;
            }
            else{
                cookieIndex++;
            }
        }
        return maxNum;
    }
};
/*
Intuition
To assign cookies to children optimaly we should give for each child the closest higher cookie. By using this greedy approach overall sum of wasted cookies will be minimum amoung all. To use this greedy solution in effective way we can sort both arrays and use two pointers. We should move pointer of children only if there is enough cookies to make that child content. In each step we will try to make content child at position pointerG by searching the closes higher cookie value.

Time complexity: The time complexity is O(n log n), where n is the length of the larger array between g and s, due to the sorting step.
Space complexity: The space complexity is O(1).*/