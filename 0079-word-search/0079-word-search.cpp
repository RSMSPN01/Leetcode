// This is the most optimal approach for this,earlier even if we find the answer
// we still come back and do search for other paths but here if one path is
// found directly return from there no need to search for other paths.

// Athough the basic approach is already submitted earlier
class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col,
                int indx) {
        // base case to handle all the values
        if (indx == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board[0].size() || board[row][col] == '#') {
            return false;
        }
        // check all the other four sides now
        // if any time we reach end means return directly
        if (board[row][col] == word[indx]) {
            // mark visited
            char temp = board[row][col];
            board[row][col] = '#';
            // explore ahead
            if (helper(board, word, row + 1, col, indx + 1) ||
                helper(board, word, row - 1, col, indx + 1) ||
                helper(board, word, row, col + 1, indx + 1) ||
                helper(board, word, row, col - 1, indx + 1)) {
                return true;
            }
            // undo the changes
            board[row][col] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};