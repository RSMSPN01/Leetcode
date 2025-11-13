// Last updated: 11/13/2025, 1:14:18 PM
class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k == countBits(i)) {
                total += nums[i];
            }
        }
        return total;
    }
};