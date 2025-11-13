// Last updated: 11/13/2025, 1:15:22 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};