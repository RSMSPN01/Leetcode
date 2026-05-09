// Approach : I don't know where to and how to use queue in this i think i can
// do this question using only single array and one traversal lets see

// My Approach : First traverse till k and find the next greater value, but i
// realise this is not going to work because the max value can get out of the
// range, i have to continously check for each window its maximum

// The extreme naive approach is using two loops and time complexity will be
// O(n*k) and space complexity O(n)

// Lets go with hints and see what we can get
// so i can only think of one solution with queue, maintain a k size queue and
// push the next value in and pop the last value and before checking just check
// that is value which is going to be popped is it the maxValue if yes then rec-
// alculate the current window max but this work same as array there is no
// change in the time and space // i am not be able to write the whole code for
// it

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // trying striver approach
        deque<int> dq;
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            // first step is to remove elements out of window size
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // remove any smaller values then current value
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i); // push index not actual value in it
            // check even if there are k window elements or not
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;

        // This approach i can't understand how to recalculate the max sum, i
        // have to remove all the values from the queue once and then store it
        // somewhere which is costly and time consuming as well

        // queue<int> window(k);
        // int maxval = nums[0];
        // vector<int> result;
        // // lets push the value in the queue till k
        // for (int i = 0; i < k; i++) {
        //     // first k values are pushed in
        //     window.push(nums[i]);
        //     maxVal = max(maxVal, nums[i]);
        // }
        // for (int i = k; i < nums.size(); i++) {
        //     // only again calculate the value of max if it is popped out
        //     if (window.front() != maxVal) {
        //         result.pop();
        //         window.push(nums[i]);
        //         result.push(maxVal);
        //     } else {
        //         result.pop();
        //         window.push(nums[i]);
        //         // recalculate the new max value
        //     }
        // }
    }
};