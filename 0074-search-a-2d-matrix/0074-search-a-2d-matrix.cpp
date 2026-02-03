// Naive Approach : Use double loops and search for the target linearly
// T.C - O(n^2) and S.C - O(1)

// Optimal Approach : We can took the advantage of sorted rows and columns, we
// can start searching either from the top most right or top bottom left bcs it
// will provide us the path where we can consider or skip the numbers
// Time.C = O(m+n), Space.C = O(1)

// I think this is the most optimal Appraoch but there exists even a better
// Appraoch then this with Time.C = O(log(m+n)), Space.C = O(1) now going to
// learn about that.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time.C = O(log(m*n)), Space.C = O(1)
        // Intiution : Flatten the whole array and look at it as a 1D array and
        // apply the bs directly on it bcs it is already sorted

        // just the thing to be note here how the row and columns index has been
        // devrived from the mid value.
        // col index = we know there are m no.s in columns so divide them by col
        // why bcs that must be divisible by its columns
        // in simmple words just remember that if we need to find the row and col
        // these are the formulas for it 
        // row = mid/m and col = mid%m (that is is not further explanation)
        int n = matrix.size(), m = matrix[0].size();
        int low = 0,high = (m*n) - 1,mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if(matrix[mid/m][mid%m] == target) {
                return true;
            }else if(matrix[mid/m][mid%m] < target) {
                low = mid + 1;
            }else {
                high = mid -1;
            }
        } 
        return false;

        // Optimal Appraoch ; Time.C = O(m+n), Space.C = O(1)
        // starting from the top right corner of matrix
        // int n = matrix.size(), m = matrix[0].size();
        // int row = 0, col = m - 1;
        // while (row < n && col >= 0) {
        //     if (matrix[row][col] == target) {
        //         return true;
        //     } else if (matrix[row][col] > target) {
        //         // target is smaller go to lower side
        //         col--;
        //     } else {
        //         // target is greater go to higher side
        //         row++;
        //     }
        // }
        // return false;
    }
};