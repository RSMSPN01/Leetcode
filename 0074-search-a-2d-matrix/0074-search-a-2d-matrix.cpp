// Naive Approach : Use double loops and search for the target linearly
// T.C - O(n^2) and S.C - O(1)

// Optimal Approach : We can took the advantage of sorted rows and columns, we
// can start searching either from the top most right or top bottom left bcs it
// will provide us the path where we can consider or skip the numbers
// Time.C = O(log(m*n)), Space.C = O(1) 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // starting from the top right corner of matrix
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                // target is smaller go to lower side
                col--;
            } else {
                // target is greater go to higher side
                row++;
            }
        }
        return false;
    }
};