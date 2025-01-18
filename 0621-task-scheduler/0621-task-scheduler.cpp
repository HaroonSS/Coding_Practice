#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Frequency count of tasks
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Count the number of tasks with maximum frequency
        int numMaxFreqTasks = count(freq.begin(), freq.end(), maxFreq);

        // Calculate the minimum intervals needed
        int intervals = (maxFreq - 1) * (n + 1) + numMaxFreqTasks;

        // Return the maximum of intervals and the total number of tasks
        return max((int)tasks.size(), intervals);
    }
};
