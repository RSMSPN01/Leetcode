// Last updated: 12/14/2025, 5:06:57 AM
class Solution {
public:
// Approach : I think it is similar like kadan's algorithm. In which we keep
// on adding the values and if we get even below zero we again update and keep
// on tracking the maximum and updating it
// bcs it is a subarray and max sum should be contiguos 
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN; // just to atleast store the first value
        for(int i = 0;i<nums.size();i++){
            // update the max here
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0){
                sum = 0; // reset the total sum again
            }
        }
        return maxSum;
    }
};