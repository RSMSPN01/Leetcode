// Last updated: 11/13/2025, 1:14:46 PM
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1){return false;}
        int sum = 1;
for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
        sum += i;
        sum+= num / i;
    }
}
        if (sum == num) {
            return true;
        } else {
            return false;
        }
    }
};