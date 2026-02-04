// Naive Approach : We can traverse the whole array each row one by one and
// check for the peak element
// Time.C = O(n^2), Space.C = O(1)

// Better Approach : We can use B.S here bcs, in an 1d array we can use bs to
// find the peak element, and here we will do the same thing
// Time.C = O(nlogn) Space.C = O(1)
// don't know why this Approach don't work just fail last 3 test cases
// and others have used a different method to do the same approach.

// Optimla Approach : We can do this question on observation based too in which
// we will check if the element to its right and bottom is greater or not if yes
// then keep on moving to the greater element you will find the peak itself but
// in that Approach handling edge cases is the most difficult task but it can be
// done Time.C = O(m+n), Space.C = O(1)

class Solution {
public:
    // An error occured for few test cases, what if the last element is peak but
    // there exist a larger a peak element in the array but by my logic it will
    // directly return that which is wrong, Even the first or last element is
    // peak we still need to traverse the array for a larger peak element

    // function to find out the peak element in 1D array
    // vector<int> peakElementAndIndex(vector<int>& mat){

        // This appraoch failed dude on the last 3 test cases although great try
        // look for the better appraoch then this one
        //     int n = mat.size();
        //     int peak = 0, index = 0;
        //     // handle edge cases here
        //     // check if first and last elements are peak or not
        //     if (n == 1) {
        //         // return first element and index 0
        //         return {mat[0], 0};
        //     }
        //     if (mat[0] > mat[1]) {
        //         // store for now
        //         peak = mat[0];
        //         index = 0;
        //     }
        //     if (mat[n - 1] > mat[n - 2]) {
        //         if (peak < mat[n - 1]) {
        //             // this condition need to be checked every Time
        //             index = n - 1;
        //             peak = mat[n - 1];
        //         }
        //         // return {mat[n - 1], n - 1};
        //     }
        //     // else apply bs here
        //     int low = 1, high = n - 2, mid = 0;
        //     while (low <= high) {
        //         mid = low + (high - low) / 2;
        //         if (mat[mid] > mat[mid - 1] && mat[mid] > mat[mid + 1]) {
        //             // return {mat[mid], mid};
        //             if (peak < mat[mid]) {
        //                 // this condition need to be checked every Time
        //                 return {mat[mid], mid};
        //             }
        //             // use break else it will just run infinite times.
        //             break;
        //         } else if (mat[mid + 1] > mat[mid - 1]) {
        //             low = mid + 1;
        //         } else {
        //             high = mid - 1;
        //         }
        //     }
        //     return {peak, index};
        // }
        // vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //     int maxElement = 0, row = -1, col = -1;
        //     int n = mat.size();
        //     for (int i = 0; i < n; i++) {
        //         // it will return the peak and its index value
        //         vector<int> temp = peakElementAndIndex(mat[i]);
        //         if (temp[0] > maxElement) {
        //             // it will only return the maximum peak element in the
        //             matrix
        //             maxElement = temp[0];
        //             row = i;
        //             col = temp[1];
        //         }
        //     }
        //     return {row, col};
        // }

        // I am not going to solve the problem for O(nlogm ) watch video for
        // that
        // This is the most optimal appraoch for this one O(m+n)

        int val(vector<vector<int>> & mat, int i,
                  int j){// this check that even the value exists or not
                         // if exist then return the value else return -1
                         if (i < 0 || j < 0 || i >= mat.size() ||
                             j >= mat[0].size()){return -1;
} return mat[i][j];
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    // approach is simple check even the index exists or not if it exists then
    // move towards the greater element and if no possible moves will left it
    // will return the value.
    int i = 0, j = 0;
    while (true) {
        if (val(mat, i + 1, j) > val(mat, i, j)) {
            i++;
            continue;
        }
        if (val(mat, i, j + 1) > val(mat, i, j)) {
            j++;
            continue;
        }
        if (val(mat, i - 1, j) > val(mat, i, j)) {
            i--;
            continue;
        }
        if (val(mat, i, j - 1) > val(mat, i, j)) {
            j--;
            continue;
        }
        return {i,j};
    }
    return {-1, -1};
}
};