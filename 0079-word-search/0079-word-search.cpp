class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        // Base case: if we've matched the entire word
        if (index == word.size()) {
            return true;
        }

        // Boundary and character check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }

        // Temporarily mark the cell as visited
        char c = board[i][j];
        board[i][j] = '*';

        // Explore all four directions
        bool found = dfs(board, i - 1, j, word, index + 1) ||
                     dfs(board, i + 1, j, word, index + 1) ||
                     dfs(board, i, j - 1, word, index + 1) ||
                     dfs(board, i, j + 1, word, index + 1);

        // Restore the cell's original value (backtracking)
        board[i][j] = c;

        return found;
    }
};
/*
Time Complexity:

\U0001d442
(
\U0001d440
×
\U0001d441
×
4
\U0001d43f
)
O(M×N×4 
L
 ), where 
\U0001d440
×
\U0001d441
M×N is the grid size and 
\U0001d43f
L is the word length.
Each cell can be visited in up to 4 directions.
Space Complexity:

\U0001d442
(
\U0001d43f
)
O(L) for the recursion stack, where 
\U0001d43f
L is the length of the word.*/