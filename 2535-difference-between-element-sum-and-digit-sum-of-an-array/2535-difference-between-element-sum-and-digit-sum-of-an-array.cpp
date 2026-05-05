class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int absoluteSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            if (nums[i] >= 10) {
                int temp = nums[i];
                while (temp > 0) {
                    absoluteSum += temp % 10;
                    temp /= 10;
                }
            } else {
                absoluteSum += nums[i];
            }
        }
        return (totalSum - absoluteSum);
    }
};