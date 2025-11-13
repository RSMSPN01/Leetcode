// Last updated: 11/13/2025, 1:15:57 PM
class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        if (nums[0] == target) {
            return 0;
        }
        int start = 0, end = nums.size() - 1, mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if ((mid == 0 && nums[mid] == target) ||
                (nums[mid] == target && nums[mid - 1] != target)) {
                return mid;
            } else if (target <= nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int lastOccurence(vector<int>& nums, int target, int start) {
        if (nums[nums.size() - 1] == target) {
            return nums.size() - 1;
        }
        int end = nums.size() - 1, mid = 0, n = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if ((mid == n && nums[mid] == target) ||
                (nums[mid] == target && nums[mid + 1] != target)) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr(2, -1);
        if (nums.size() == 0) {
            return arr;
        }
        int first = firstOccurence(nums, target);
        if (first == -1) {
            return arr;
        } else {
            arr[0] = first;
            arr[1] = lastOccurence(nums, target, first);
        }
        return arr;
    }
};