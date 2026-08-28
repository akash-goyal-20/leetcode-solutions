class Solution {
public:

    bool isSafe(int row, int col, int k, vector<vector<char>>& board) {

        char can = '0' + k;

        // Check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == can) {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == can) {
                return false;
            }
        }

        // Check 3 x 3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == can) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Find an empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    // Try numbers 1 to 9
                    for (int k = 1; k <= 9; k++) {

                        if (isSafe(row, col, k, board)) {

                            board[row][col] = '0' + k;

                            // If solution is found
                            if (solve(board)) {
                                return true;
                            }

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No number worked for this cell
                    return false;
                }
            }
        }

        // No empty cells left
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};