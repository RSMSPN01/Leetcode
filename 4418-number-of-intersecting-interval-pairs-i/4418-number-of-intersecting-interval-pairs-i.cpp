class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& v) {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (max(v[i][0], v[j][0]) <= min(v[i][1], v[j][1])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};