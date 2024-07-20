class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstColumn = false;
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        
        // Check if the first row needs to be set to zero
        for (int i = 0; i < columnSize; i++) {
            if (matrix[0][i] == 0) {
                firstRow = true;
                break; // No need to continue, we already know first row needs to be zeroed
            }
        }
        
        // Check if the first column needs to be set to zero
        for (int i = 0; i < rowSize; i++) {
            if (matrix[i][0] == 0) {
                firstColumn = true;
                break; // No need to continue, we already know first column needs to be zeroed
            }
        }
        
        // Use the first row and column to mark zero positions
        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < columnSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set zeroes based on marks in the first row and column
        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < columnSize; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Finally, set the first row to zero if needed
        if (firstRow) {
            for (int i = 0; i < columnSize; i++) {
                matrix[0][i] = 0;
            }
        }
        
        // Finally, set the first column to zero if needed
        if (firstColumn) {
            for (int i = 0; i < rowSize; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
