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
    vector<int> prevSmaller(vector<int>& nums) {
        vector<int> pse(nums.size());
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[i] <= nums[s.top()]) {
                s.pop();
            }
            pse[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }
    vector<int> nextSmaller(vector<int>& nums) {
        vector<int> nse(nums.size());
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] <= nums[s.top()]) {
                s.pop();
            }
            nse[i] = (s.empty()) ? nums.size() : s.top();
            s.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = prevSmaller(heights);
        vector<int> nse = nextSmaller(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxArea;
    }
};