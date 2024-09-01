class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> results;

        for (auto query : queries) {
            int x = query[0];
            int y = query[1];
            int distance = abs(x) + abs(y); 

            pq.push(distance);

            if (pq.size() > k) {
                pq.pop();
            }
            if (pq.size() == k) {
                results.push_back(pq.top());
            } else {
                results.push_back(-1);
            }
        }

        return results;  
    }
};