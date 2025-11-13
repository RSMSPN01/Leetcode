// Last updated: 11/13/2025, 1:16:04 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if(nums[i]!=nums[index-1]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};