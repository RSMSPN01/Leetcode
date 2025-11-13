// Last updated: 11/13/2025, 1:15:45 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> v;
        while (i < m || j < n) {
            int num1 = INT_MAX;
            int num2 = INT_MAX;
            if (i < m) {
                num1 = nums1[i];
            }
            if (j < n) {
                num2 = nums2[j];
            }
            if (num1 < num2) {
                v.push_back(num1);
                i++;
            } else {
                v.push_back(num2);
                j++;
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = v[i];
        }
    }
};