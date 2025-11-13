// Last updated: 11/13/2025, 1:15:43 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = prices[0], n = prices.size(), profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < minValue) {
                minValue = prices[i];
            } else {
                profit = max(profit, prices[i] - minValue);
            }
        }
        return profit;
    }
};