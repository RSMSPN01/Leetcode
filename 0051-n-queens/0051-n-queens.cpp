class Solution {
public:
    void helper(vector<vector<string>>& ans, vector<string>& board, int n,
                int row, vector<int>&ld, vector<int>&rd, vector<int>&upC) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (upC[col] == 0 && rd[row + col] == 0 &&
                ld[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                upC[col] = 1;
                rd[row + col] = 1;
                ld[n - 1 + col - row] = 1;
                helper(ans, board, n, row + 1, ld, rd, upC);
                board[row][col] = '.';
                upC[col] = 0;
                rd[row + col] = 0;
                ld[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); 
        vector<vector<string>> result;
        vector<int> leftDiagonal(2 * n - 1, 0);
        vector<int> rightDiagonal(2 * n - 1, 0);
        vector<int> uppperColumn(n, 0);
        helper(result, board, n, 0, leftDiagonal, rightDiagonal, uppperColumn);
        return result;
    }
};