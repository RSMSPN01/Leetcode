// Last updated: 12/5/2025, 10:19:13 AM
class Solution {
public:
    // Approach : i will use the same approach as we use in to print all the
    // subsets of a string using binary bits to keep track The total subsets to
    // print is 2 power(size of array) 2^3  8 now we run a loop and check if the
    // bit is set or not if set then print the according value
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v(pow(2, nums.size())) ; // create the empty vector to store all the values
        for (int i = 0; i < pow(2, nums.size()); i++) {
            int x = i;
            for (int j = 0; j < nums.size(); j++) {
                // check for the bits are set or not
                if (x & (1 << j)) { // if bit is set then print it or push it.
                    v[i].push_back(nums[j]);
                }
            }
        }
        return v;
    }
};