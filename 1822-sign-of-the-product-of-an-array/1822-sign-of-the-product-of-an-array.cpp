class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for (int i : nums) {
            if (i == 0) {
                return 0;
            }
            if (i < 0) {
                product *= -1;
            } else {
                product *= 1;
            }
        }
        if (product < 0) {
            return -1;
        }
        return 1;
    }
};