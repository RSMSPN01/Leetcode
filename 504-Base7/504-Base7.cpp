// Last updated: 11/13/2025, 1:14:48 PM
class Solution {
public:
    string convertToBase7(int num) {
        string s = "";
        if (num == 0) {
            return "0";
        }
        bool isNegative = num < 0;
        num = abs(num);
        while (num > 0) {
            int rem = num % 7;
            s = char(rem + '0') + s;
            num /= 7;
        }
        if (isNegative) {
            s = "-" + s;
        }
        return s;
    }
};