// Last updated: 11/13/2025, 1:14:39 PM
class Solution {
public:
    bool checkSetBits(int i) {
        int n = 0;
        while (i != 0) {
            i = i & (i - 1);
            n++;
        }
        static unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        return primes.count(n);
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (checkSetBits(i)) {
                count++;
            }
        }
        return count;
    }
};