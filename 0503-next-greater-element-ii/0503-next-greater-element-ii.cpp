// Approach : Same appraoch as the previous questoin, but this time instead of
// traversing from one side we will traverse from both the sides and in the end
// we return the max of between these two
// Time.C = O(n), Space.C = O(n) // instead of using two loops to calculate the
// postfix and prefix we can even do this in one traversal too

// This appraoch won't work we don't include the prefix greater elements in this

// We can traverse the array twice and keep on storing the values approach 2
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Approach Time.C = O(2n), Space.C = O(n)

        int n = nums.size();
        int i = n - 1;     // pointer start from last
        int j = n * 2 - 2; // This will run twice
        stack<int> s;
        vector<int> result(n);
        while (j >= 0) {
            while (!s.empty() && nums[i % n] >= s.top()) {
                s.pop();
            }
            if (s.empty()) {
                result[i % n] = -1;
            } else {
                result[i % n] = s.top();
            }
            s.push(nums[i % n]);
            // i--;
            if (i == 0) {
                i = n - 1;
            } else {
                i--;
            }
            j--; // run the loop twice so this way
        }
        return result;

        // This approach only works for few test cases but not for all

        // vector<int> prefixMax(nums.size());
        // vector<int> postfixMax(nums.size());
        // vector<int> result(nums.size());
        // stack<int> s;
        // // calculate the post fix max
        // // traversing from the back side
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     while (!s.empty() && nums[i] >= s.top()) {
        //         s.pop();
        //     }
        //     if (s.empty()) {
        //         postfixMax[i] = -1;
        //     } else {
        //         postfixMax[i] = s.top();
        //     }
        //     s.push(nums[i]);
        // }
        // // calculate the prefix max
        // // start from the left side of the array
        // stack<int> s1;
        // for (int i = 0; i < nums.size(); i++) {
        //     while (!s1.empty() && nums[i] >= s1.top()) {
        //         s1.pop();
        //     }
        //     if (s1.empty()) {
        //         prefixMax[i] = -1;
        //     } else {
        //         prefixMax[i] = s1.top();
        //     }
        //     s1.push(nums[i]);
        // }
        // // in the end store the max of postfix and prefix and return
        // for (int i = 0; i < nums.size(); i++) {
        //     result[i] = max(prefixMax[i], postfixMax[i]);
        // }
        // return result;
    }
};