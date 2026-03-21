// Approach : Traverse the board, and check for three conditions, can be place
// the value or not if we can then place if not then do backtrack, this is what
// i am thinking to solve the question

// Thinking for it is easy but actually implemting, and how to backtrack like
// from which particular step is where i am stuck at

class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int row, int col, char value) {
        // check for that three conditions
        // there should be any previous value same to this value
        for (int i = 0; i < 9; i++) {
            // check row
            if (board[row][i] == value) {
                return false;
            }
            // check column
            if (board[i][col] == value) {
                return false;
            }
            // check that particular box
            // this is the direct formula to check this
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // if it is dot then we can actually place something here
                    // which value is safe to place check that
                    for (char c = '1'; c <= '9'; c++) {
                        if (canPlace(board, i, j, c)) {
                            // if value can be placed so place it
                            board[i][j] = c;
                            // call the recursion again
                            if (solve(board) == true) {
                                // if we found any possible answer return from
                                // there
                                return true;
                            }
                            // undo the things
                            board[i][j] = '.';
                        }
                    }
                    // if there is no value to place then move back from
                    // here
                    return false;
                }
            }
        }
        // after fully traversing the board, there is no empty space left, so we
        // have filled all the spaces there.
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // my approach of solving the problem
        solve(board);
    }
};