class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());
           	//sort(ins.begin(), ins.end(), [](intervals a, intervals b) {return a[0] < b[0];}
            vector<vector < int>> result;
            result.push_back(intervals[0]);

            for (int i = 1; i < intervals.size(); i++)
            {
                if (result.back()[1] >= intervals[i][0])
                    result.back()[1] = max(result.back()[1], intervals[i][1]);
                else
                    result.push_back(intervals[i]);
            }
            return result;
        }
};

// int index = 0;
// // Traverse all input Intervals
// for (int i = 1; i <= intervals.size(); i++)
// {
//    	// If this is not first Interval and overlaps
//    	// with the previous one
//     if (intervals[index][1] >= intervals[i][0])
//     {
//        	// Merge previous and current Intervals
//         intervals[index][1] = max(intervals[index][1], intervals[i][1]);
//     }
//     else
//     {
//         index++;
//         intervals[index] = intervals[i];
//     }
// }
// return intervals;