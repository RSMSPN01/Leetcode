// Last updated: 11/13/2025, 1:15:54 PM
class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                arr[i] = n + 1; // handle all the negative and zeros values by
                                // making them out of the bound.
            }
        }
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]);
            if (index <= n) {
                arr[index - 1] = -abs(arr[index - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};