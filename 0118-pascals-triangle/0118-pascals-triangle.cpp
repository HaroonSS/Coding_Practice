class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
		}
		ans.push_back(row);
	}
	return ans;

        
    }
};
/*
     vector<vector<int>> ans(numRows);
// 1.first and last element is always 1
// 2.any middle element of numRows i and col j ,is equal to sum of elements of numRows (i-1) at index j and (j-1) respectively.
    for (int i = 0; i < numRows; i++)
    {
        ans[i].resize(i+1, 1);
        //starts with 1  
        //ans[i][0] = 1;
        //middle 
        for (int j = 1; j < i; j++) 
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        //ends with 1 
        //ans[i][i] = 1;
    }
    return ans;
    */