// Naive Approach : Start from value 0 and keep on updating the numbers till the
// length is smaller then n, for each number run a loop and check at each
// indexes that either it is a good string or not, but that take hell lot of
// time Time.C = O(n*n), Space.C = O(n) extra space to store prime values

// Better Approach : So i am looking for some sort of pattern between the
// numbers how each number is derived from its previous number for eg if n = 5,
// n is odd so we can call for fun(n-1) * 5 and we can get the value like this
// but still this can take O(n) time and O(n) call stack space

// There must be some better way which i can't able to find by myself, lets look
// some help.
// so in this problem we don't have to find the strings which are good or not we
// just have to find that how many good strings can be formed, it is pure maths

// if n = 6 means _ _ _ _ _ _, now how many even indexes are there (n+1) /2 and
// how many odds (n/2), so we know that at even indexes we can only have values
// (0,2,4,6,8) total 5 values and at odd indexes only prime (2,3,5,7) means 4
// values so we simply need to find the total combination so multiply all of
// that 5*4*5*4*5*4 and this can also we written as 5^(even indexes) and 4^(odd
// index) more simply 5^(n+1)/2 * 4^(n/2)// and this will be our answer, this is
// the most simple way i can explain this, still you don't get idea go watch
// CSWM video
// #define modulo 1e9 +7
long long mod = 1e9 + 7;
class Solution {
public:
    // reference code used here
    long long power(long long base, long long exp) {
        long long result = 1;
        // why we only mod base is bcs we can modify it but if we 
        // mod the exponent then the result may varry so don't mod
        // that .
        base = base % mod;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        // intiution is explained above
        // so here value of n could be very large and pow can overflow
        // so we need custom power function
        // long long ans = pow(5,n+1/2) * pow(4,n/2);

        // custom power function
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        long long part1 = power(5, evenCount);
        long long part2 = power(4, oddCount);
        return (part1 * part2) % mod;
    }
};