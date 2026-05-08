class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n != 0) {
            int value = n % 10;
            n /= 10;
            product *= value;
            sum += value;
        }
        return product - sum;
    }
};