// Last updated: 11/13/2025, 1:14:44 PM
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
     sort(nums.begin(),nums.end());
     double first=nums[n-1]*nums[n-2]*nums[n-3]; 
     double second=nums[n-1]*nums[0]*nums[1]; 
     return max(first,second); 
    }
};