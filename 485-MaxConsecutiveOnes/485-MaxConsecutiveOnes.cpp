// Last updated: 12/11/2025, 3:41:57 PM
class Solution {
public:
// approach : simply run a loop and check for the current and the next element if it is 1
// then update the count and also update the maxcount.
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]){
                count++; // if one then simply count and update
                maxCount = max(maxCount,count);
            }else{
                count = 0;// count is reset to zero
            }
        }
        return maxCount;
        // // handle edge case with only one element in the array.
        // if(nums.size() == 1 && nums[0]){
        //     return 1;
        // }else if(nums.size() == 1 && !nums[0]){
        //     return 0;
        // }
        // int count = 0;
        // int maxCount = 0;
        // bool flag = false;
        // for(int i = 0;i<nums.size()-1;i++){
        //     if(nums[i]){
        //         flag = true;
        //     }
        //     if(nums[i] == 1 && nums[i] == nums[i+1]){
        //         //check current and next element and updating the max count.
        //         count++;
        //         maxCount = max(maxCount,count);
        //     }else{
        //         // reseting the count variable when 0 appears in the array.
        //         count = 0;
        //     }
        // }
        // if(nums.size()-1 == 1){
        //     flag = true;
        // }
        // return (flag)?maxCount+1:maxCount;
    }
};