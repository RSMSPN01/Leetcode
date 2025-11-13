// Last updated: 11/13/2025, 1:15:01 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};
