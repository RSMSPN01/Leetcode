// Last updated: 11/13/2025, 1:14:35 PM
class Solution {
public:
    int binaryGap(int n) {
        if ((n & (n - 1)) == 0) {
            return 0;
        }
        int maxi = 0;
        int count = 0;
        while (n > 0) {
            if (n & 1) {
                count = 1;
                n >>= 1;
                while (n>0 && (n & 1) != 1 ) {
                    count++;
                    n >>= 1;
                }
                maxi = max(count, maxi);
            } else {
                n >>= 1;
            }
        }
        return maxi;
    }
};