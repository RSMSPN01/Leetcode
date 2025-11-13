// Last updated: 11/13/2025, 1:15:10 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int valueSum = 0;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            valueSum+=nums[i];
            count += i+1;
        }
        return (count-valueSum);
    }
};