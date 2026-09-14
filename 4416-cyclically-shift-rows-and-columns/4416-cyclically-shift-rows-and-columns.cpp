// Approrach : So first think of cyclic shifting of rows/ columns
// simply run loops and keep on reversing them
class Solution {
public:
    vector<int> shiftLeft(vector<int>& v, int k) {
        // shift the array k times to the left
        int n = v.size();
        // k = n % k; // look for mistake later
        k = k % n; // round that off
        // using reverse technique here
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
        reverse(v.begin(), v.end());
        return v;
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        // vector<vector<int>> finalResult;
        // first traverse the row side and make changes
        for (int i = 0; i < n; i++) {
            shiftLeft(grid[i],
                      rowShift[i]); // changes made directly in the grid
        }
        // traverse colm side
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(grid[j][i]);
            }
            shiftLeft(temp, colShift[i]);
            // now make the chances in original grid as well
            for (int k = 0; k < n; k++) {
                grid[k][i] = temp[k];
            }
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return grid;
    }
};