// Approach : Naive way run a loop from 1 to threshold and in the end you will
// get the final result but it will take linear time so optimize that even more.

// Better Way : Similar to the previous question, just a little change in the valid
// function, other then that the whole logic is similar normal bs.

class Solution {
public:
    bool valid(int divisor, vector<int>& nums, int t){
        int totalSum = 0;
        for(int i = 0;i<nums.size();i++){
            totalSum += (nums[i] + divisor - 1) / divisor;
            // you can also use celi function here
        }
        if(totalSum <= t){
            // it means it is a valid divisor
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // so the max possible divisor could be the maximum value in the array.
        int low = 1, high = *max_element(nums.begin(),nums.end()), mid = 0;
        int minDivisor = INT_MAX;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if(valid(mid,nums,threshold)){
                // update the value, we have found a smaller divisor
                minDivisor = min(mid,minDivisor);
                // move the low ahead bcs there could be more 
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return minDivisor;
    }
};