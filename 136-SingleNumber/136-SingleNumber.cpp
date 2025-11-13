// Last updated: 11/13/2025, 1:15:39 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i =0;i<nums.size();i++){
            res = res ^ nums[i];
        }
        return res;
    }
};