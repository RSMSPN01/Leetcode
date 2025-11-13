// Last updated: 11/13/2025, 1:15:30 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major = 0,count = 0;
        for(int i =0;i<n;i++){
            if(count==0){
                major = nums[i];
            }
            if(nums[i]==major){
                count++;
            }else{
                count--;
            }
        }
        return major;
    }
};