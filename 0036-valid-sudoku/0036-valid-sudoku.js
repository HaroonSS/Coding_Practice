/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    // Create hash sets for rows, columns, and boxes
    const rows = Array.from({ length: 9 }, () => new Set());
    const cols = Array.from({ length: 9 }, () => new Set());
    const boxes = Array.from({ length: 9 }, () => new Set());

    for (let row = 0; row < 9; row++) {
        for (let col = 0; col < 9; col++) {
            const value = board[row][col];

            // Skip empty cells
            if (value === ".") continue;

            // Calculate the box index
            const boxIndex = Math.floor(row / 3) * 3 + Math.floor(col / 3);

            // Check for duplicates in row, column, and box
            if (rows[row].has(value) || cols[col].has(value) || boxes[boxIndex].has(value)) {
                return false;
            }

            // Add the value to the respective sets
            rows[row].add(value);
            cols[col].add(value);
            boxes[boxIndex].add(value);
        }
    }

    // If no duplicates are found, the board is valid
    return true;
};
