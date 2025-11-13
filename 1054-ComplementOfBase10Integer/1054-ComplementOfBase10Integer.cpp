// Last updated: 11/13/2025, 1:14:28 PM
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 0;
        }
        int res = 0;
        int i = 0;
        while (n > 0) {
            int bit = !(n & 1);
            res = res | (bit << i);
            i++;
            n >>= 1;
        }
        return res;
    }
};