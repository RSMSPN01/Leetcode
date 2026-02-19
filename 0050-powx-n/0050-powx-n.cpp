// Already solved this question using bit manipulation, now going to try this
// using recursion, and it is a very simple and easy question based on even and
// odd power just return it.

class Solution {
public:
    double pow(double x, long n) {
        // base case
        if (n == 1) {
            return x;
        }
        if (n & 1) {
            // if odd
            return x * pow(x, n - 1);
        } else {
            // even
            return pow(x * x, n / 2);
        }
    }
    double myPow(double x, int n) {
        // handle edge cases and precompute some values
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        // add these two checks or else convert the int n to double to 
        // store INT_MAX and INT_MIN values
        // long ni = n;
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if (n < 0) {
            // make it valid value
            // ni = labs(n);
            n = abs(n);
            x = 1 / x;
        }
        return pow(x, n);
    }
};