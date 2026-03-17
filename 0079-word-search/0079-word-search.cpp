// Brute Approach : I don't know how to solve this with backtracking but, a
// general approach can be used in which we traverse the whole array and the
// point where we find the first word we will start to find the word from there

// So the brute force approach is good only if we don't have duplicates, else it
// will give error, when we multiple same letters going from one place

// backtracking Approach : i have not solve any question like this so lets watch
// video first and then comeback here. So the approach is very simple from each
// index just look and keep on doing the backtrack

class Solution {
public:
    // Brute Force - Only works if there are no duplicates
    // Time.C = O(n*m*k*(n+m)), Space.C = O(1)
    // bool matchWord(vector<vector<char>>& board, string& word, int i, int j) {
    //     // function help to find the word in O(m+n) time
    //     int m = board.size();
    //     int n = board[0].size();
    //     for (int k = 1; k < word.length(); k++) {
    //         bool top = false, bottom = false, right = false, left = false;
    //         if (i != 0) {
    //             top = true;
    //         }
    //         if (i != m - 1) {
    //             bottom = true;
    //         }
    //         if (j != 0) {
    //             left = true;
    //         }
    //         if (j != n - 1) {
    //             right = true;
    //         }
    //         if (top && board[i - 1][j] == word[k]) {
    //             i = i - 1;
    //         } else if (bottom && board[i + 1][j] == word[k]) {
    //             i = i + 1;
    //         } else if (left && board[i][j - 1] == word[k]) {
    //             j = j - 1;
    //         } else if (right && board[i][j + 1] == word[k]) {
    //             j = j + 1;
    //         } else {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int m = board.size();
    // int n = board[0].size();
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (board[i][j] == word[0]) {
    //             // search from the first word we found
    //             if (matchWord(board, word, i, j)) {
    //                 return true;
    //             }
    //         }
    //     }
    // }
    bool backtrack(vector<vector<char>>& board, string word, int i, int j,int ind) {
        if (ind == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
                board[i][j] == '#' || board[i][j] != word[ind]) {
            return false;
        }
        // simple backtrack template
        char temp = board[i][j];
        // include first
        board[i][j] = '#';
        // backtrack
        bool result = backtrack(board, word, i - 1, j, ind + 1) ||
                      backtrack(board, word, i + 1, j, ind + 1) ||
                      backtrack(board, word, i, j - 1, ind + 1) ||
                      backtrack(board, word, i, j + 1, ind + 1);
        // exclude
        board[i][j] = temp;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};