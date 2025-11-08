class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        // case 1: no overlapping case before the merge intervals
        // compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        // case 2: overlapping case and merging of intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

// Case 2 explanation,
// {[6,8], [10,12], [15,16], [20,22], [23,24]}
// and we need to insert [13,18]

// The first while loop will make result = {[6,8], [10,12]}. Then we terminate on [15,16] since 16 is !< 13. 
// Then the second while loop will compare [13,18]and [15,16] and see if 18 >= 15. Yes, this is true. 
// So we update newInterval to be [13,18]. This part might be confusing, but bear with me. 
// Now we compare [13,18] and [20,22]. Here, 18 >= 20 is NOT true, so we terminate. 
// And then insert into result so result = {[6,8], [10,12], [13,18]}. 
// As I said earlier, the easier way to think about this is that 18 < 20, meaning there is no
// longer an overlap, and we can now terminate the loop.