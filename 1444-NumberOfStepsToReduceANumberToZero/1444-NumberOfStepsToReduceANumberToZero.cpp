// Last updated: 11/13/2025, 1:14:24 PM
class Solution {
public:
    int numberOfSteps(int num) {
        int step = 0;
        if (num == 0 || num == 1) {
            return num;
        }
        while (num > 0) {
            if ((num & 1) == 0) { // even
                num >>= 1;
            } else {
                num = num - 1;
            }
            step++;
        }
        return step;
    }
};