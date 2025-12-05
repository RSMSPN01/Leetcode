// Last updated: 12/5/2025, 10:19:06 AM
class Solution {
public:
    // The approach is simple we just have to reverse the array three time first
    // till k second after the k elements and then at last just simple return
    // the whole array as a rotated the final output is the required array here
    // i am using the prebuilt function to rotate the vector you can even use
    // you own written rotating function for this.
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        // first reverse the array till start to n - k.
        reverse(nums.begin(), nums.begin() + (nums.size() - k));
        // second reverse it from k to the end of the array.
        reverse(nums.begin() + (nums.size() - k), nums.end());
        // fully reverse the array from start to the end.
        reverse(nums.begin(), nums.end());
    }
};