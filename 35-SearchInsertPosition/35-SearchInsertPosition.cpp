// Last updated: 11/13/2025, 1:15:56 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, mid = 0, ans = 0;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return (ans == 0 && target < nums[ans]) ? ans : ans + 1;
        return (ans == nums.size() - 1 && target > nums[nums.size() - 1]) ? ans : ans + 1;
    }
};