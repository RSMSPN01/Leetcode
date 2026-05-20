// I can't think of any naive approach either for this question let seek some
// help to get the idea
// first the naive approach idea

// Naive Approach : For any index we go left and right till we have not found
// the smaller element bcs till that it can contribute to the total area

// No you get the approach for the better appraoch that we need to calculate the
// next smaller and previous smaller value that is it

// Optimal Approach : We can do this even in single appraoch as well but i am
// not be able to understand that try next time
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // pre store the values so that we don't have to traverse them back to
        // make changes in the values which are not computed
        vector<int> pse(n, -1); // store all values as -1
        vector<int> nse(n, n);  // store all values as n
        stack<int> mono;
        for (int i = 0; i < n; i++) {
            while (!mono.empty() && heights[i] <= heights[mono.top()]) {
                int index = mono.top();
                mono.pop();
                nse[index] = i; // current value is the nse for the top element
            }
            pse[i] = (mono.empty()) ? -1 : mono.top();
            mono.push(i);
        }
       
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxArea;
    }
};