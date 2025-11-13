// Last updated: 11/13/2025, 1:16:03 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(),index = 0;
        for(int i =0;i<n;i++){
            if(nums[i]!=val){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};