// Last updated: 11/13/2025, 1:15:20 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return (n>0 &&!(n&(n-1)));
        if (n == 1) {
            return true;
        }
        if (n > 0) {
            if (n & (n - 1)) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
};