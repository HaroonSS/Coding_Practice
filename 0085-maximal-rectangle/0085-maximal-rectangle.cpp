class Solution {
public:
int largestRectangleArea(vector < int > & histo) {
      int n = histo.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && histo[st.top()] >= histo[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && histo[st.top()] >= histo[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, histo[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
}
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();  // Rows
        int n = mat[0].size();  // Columns
        int maxArea = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
/*
Time Complexity: O(N * (M+M)), where N = total no. of rows and M = total no. of columns.
Reason: O(N) for running a loop to check all rows. Now, inside that loop, O(M) is for visiting all the columns, and another O(M) is for the function we are using. The function takes linear time complexity. Here, the size of the height array is M, so it will take O(M).

Space Complexity: O(M), where M = total no. of columns.
Reason: We are using a height array and a stack of size M.*/