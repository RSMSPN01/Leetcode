// I am thinking to find out the longest sequence of all ones and then try to do
// something with that
// Or Maybe keep putting one when you incounter the zero then go to right and
// left to see what is the max you are getting

// Let see how others have done this one
// i don't really understand that this was of sliding windows to be honest
// we just simply need to find the window which is the longest and have zeros <=
// k
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zerosCount = 0;
        int n = nums.size();
        int maxLength = 0;
        while (right < n) {
            if (nums[right] == 0) {
                zerosCount++;
            }
            if (zerosCount > k) {
                // now trim down the window and then only
                if (nums[left] == 0) {
                    // if we encounter zero at left side reduce the count
                    zerosCount--;
                }
                left++;
            }
            if (zerosCount <= k) {
                // if the window is valid then only calculate the length
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};