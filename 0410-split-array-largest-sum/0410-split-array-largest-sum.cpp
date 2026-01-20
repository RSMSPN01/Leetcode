// Approach : I am not going to talk about the brute force here bcs i have already covered
// i will use bs, on this same logic which i have used to solve multiple problem like 
// these, just a little bit change in the valid fun() other than that everything is going
// to be same 

class Solution {
public:
    bool maxSum(int sum, vector<int>& nums, int k) {
        int count = 0,tempSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(tempSum + nums[i] <= sum){
                tempSum += nums[i];
            }else{
                // reset the thing
                count++;
                tempSum = nums[i];
            }
        }
        if(tempSum > 0){
            count++;
        }
        if(count <= k) {
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        int low = *max_element(nums.begin(),nums.end());
        int high = totalSum,mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if(maxSum(mid,nums,k)) {
                // if valid then search for the more minimum
                high = mid - 1;
            } else{
                low = mid + 1;
            }          
        }
        return low; 
    }
};