class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int curr = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                curr += accounts[i][j];
            }
            rich = max(rich, curr);
        }
        return rich;
    }
};