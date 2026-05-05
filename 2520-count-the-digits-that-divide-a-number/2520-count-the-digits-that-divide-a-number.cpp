class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int temp = num;
        while (num > 0) {
            int currn = num % 10;
            if (temp % currn == 0) {
                count++;
            }
            num /= 10;
        }
        return count;
    }
};