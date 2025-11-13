// Last updated: 11/13/2025, 1:14:41 PM
class Solution {
public:
    bool checkDivisibility(int i) {
        if (i <= 9) {
            return true;
        } else if (i % 10 == 0) {
            return false;
        }
        int temp = i;
        while (temp > 0) {
            int rem = temp % 10;
            if (rem == 0 || i % rem != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for (int i = left; i <= right; i++) {
            if (checkDivisibility(i)) {
                v.push_back(i);
            }
        }
        return v;
    }
};