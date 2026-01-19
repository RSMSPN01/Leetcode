// Approach : Naive way : Using linear search just keep the track of all the 
// elements which are missing from the current array and return if condition meet.

// Better way : 
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,temp = 1, count = 0;
        while (i < n) {
            if(nums[i] == temp){
                i++;
            }else{
                count++;
            }
            if(count == k){
                return temp;
            }
            temp++;
        }
        // if loop ended and nothing returns it means it is a full array
        return nums[n-1]+k-count;
    }
};