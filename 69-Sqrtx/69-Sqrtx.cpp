// Last updated: 11/13/2025, 1:15:46 PM
class Solution {
public:
    int mySqrt(int x) {
        long long int start = 0,  end = x, mid = 0, ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return int(ans);
    }
};