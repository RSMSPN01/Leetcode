class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int missing = nums[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // handle edge cases
        // This is more easy way i just handled all the edge cases like this 
        if (high == -1) {
            return k;
        } else if (low == nums.size()) {
            int miss = nums[high] - (high + 1);
            return nums[high] - miss + k;
        }
        int miss = nums[high] - (high + 1);
        return (k - miss) + nums[high];
    }
};