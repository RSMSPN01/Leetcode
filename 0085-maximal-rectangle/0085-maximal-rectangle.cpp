// No clue for this as well don't evne think for any naive approach
// So this question is based on the previous question histogram

// In this question i am going to use the most optimal way for histogram
// First do the prefix sum column wise and then find the histogram for each row

class Solution {
public:
    // most optimal way to find histogram
    // dry run or watch video if you still have any doubt
    int histogram(vector<int>& matrix) {
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
            while (!s.empty() && matrix[i] < matrix[s.top()]) {
                int height = matrix[s.top()];
                s.pop();
                int pse = (s.empty()) ? -1 : s.top();
                int nse = i;
                maxArea = max(maxArea, height * (nse - pse - 1));
            }
            s.push(i);
        }
        // some value which were not yet calculated
        while (!s.empty()) {
            int height = matrix[s.top()];
            s.pop();
            int pse = (s.empty()) ? -1 : s.top();
            int nse = matrix.size();
            maxArea = max(maxArea, height * (nse - pse - 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // first calculate prefix sum and then send values one by one
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;
        // only have to the row wise traversing
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // convert it into int then send it
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] += 1;
                }
            }
            maxArea = max(maxArea, histogram(heights));
        }
        return maxArea;
    }
};