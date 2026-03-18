// I have the intution that how the code is going to work, but converting the
// approach into code that is something i have to look up for

// There are some keyinsights which i found
// only 1 queen can pe placed in a single row
// we need to check vertical, horizontal and diagonal before placing the queen
// if we can't place a queen then backtrack till the first step

class Solution {
public:
    bool isSafeToPlace(int currRow, int currCol, vector<vector<char>>& board) {
        // row checking is handled in the code down below
        // and only check in upward direction bcs no queen's are set below
        int n = board.size();
        // checking for same col
        for (int i = 0; i < n; i++) {
            if (board[i][currCol] == 'Q') {
                return false;
            }
        }
        // check diagonal
        for (int i = currRow, j = currCol; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // check anti diagonal
        for (int i = currRow, j = currCol; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void helper(int n, vector<vector<char>>& board, int currRow, vector<vector<string>>& ans) {
        if (currRow == n) {
            vector<string> temp;
            // convert it first before adding into ans vector
            for (int i = 0; i < n; i++) {
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafeToPlace(currRow, col, board)) {
                // include and explore
                board[currRow][col] = 'Q';
                // backtrack
                helper(n, board, currRow + 1, ans);
                // undo the things
                board[currRow][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // declare the board first
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        helper(n, board, 0, ans);
        return ans;
    }
};