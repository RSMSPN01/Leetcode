// Last updated: 11/13/2025, 1:14:23 PM
class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
           sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitsA = countBits(a);
            int bitsB = countBits(b);
            if (bitsA == bitsB) return a < b;
            return bitsA < bitsB;
        });
        return arr;
    }
};