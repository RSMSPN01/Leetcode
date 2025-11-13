// Last updated: 11/13/2025, 1:14:16 PM
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> arr(n);
        arr[0] = first;
        for (int i = 1; i < n; i++) {
            arr[i] = encoded[i - 1] ^ arr[i - 1];
        }
        return arr;
    }
};