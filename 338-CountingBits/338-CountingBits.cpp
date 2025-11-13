// Last updated: 11/13/2025, 1:15:02 PM
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr = {0};
        for (int i = 1; i < n + 1; i++) {
            arr.push_back(cntBits(i));
        }
        return arr;
    }
    int cntBits(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};