// Last updated: 11/13/2025, 1:15:35 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, mid = 0;
        while (l < h) {
            mid = l + (h - l) / 2;
            if (nums[mid]> nums[h]) {
                l = mid + 1;
            } else {
                h = mid ;
            }
        }
        return nums[l];
    }
};