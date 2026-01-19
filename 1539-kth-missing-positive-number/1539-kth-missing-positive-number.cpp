// Approach : Naive way : Using linear search just keep the track of all the 
// elements which are missing from the current array and return if condition meet.

// Better way : I don't know how to solve this question in bs but i will try i already
// solve the problem in linear time lets try to think something. I tried but failed in 
// some test cases i don't want to waste more time on this question looking for help
// and then try to solve it 

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        // striver solution for the most optimal code
        // dry run the code for better understanding of how 
        // low and high are moving and why we return so.
        int n = nums.size();
        int low = 0,high = n-1,mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int actualValue = mid + 1;
            if(nums[mid] - actualValue < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low + k; // look into notes for explanation.

        // it could be so wrong but lets try
        // handle all the edge cases first
        // i try my best but it didn't work for all the test cases. 

        // int n = nums.size();
        // if(nums[n-1] == n){
        //     return n + k;
        // }
        // int low = 0,high = n-1,mid = 0;
        // while (low <= high) {
        //     mid = low + (high - low) / 2;
        //     int actualValue = mid + 1;
        //     if(nums[mid] - actualValue == k){
        //         return actualValue;
        //     }else if(nums[mid] - actualValue < k) {
        //         low = mid + 1;
        //     }else{
        //         high = mid -1;
        //     }
        // }
        // if((high == n - 1) && ((nums[high] - (high+1)) < k)) {
        //     int temp = nums[high] - (high + 1);
        //     return (nums[high] - temp + k);
        // }
        // // int actualValue = low + 1;
        // return nums[low] - k +1;



        // Naive way : O(n) time complexity to solve the problem
        // int n = nums.size();
        // int i = 0,temp = 1, count = 0;
        // while (i < n) {
        //     if(nums[i] == temp){
        //         i++;
        //     }else{
        //         count++;
        //     }
        //     if(count == k){
        //         return temp;
        //     }
        //     temp++;
        // }
        // // if loop ended and nothing returns it means it is a full array
        // return nums[n-1]+k-count;
    }
};