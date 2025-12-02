// Last updated: 12/2/2025, 3:39:20 PM
class Solution {
public:
    // approach is simple in sorted and rotated array there is only one dip in
    // the array and we have to find that dip if there there exisits only one
    // dip then return true.
    bool check(vector<int>& nums) {
        int dip = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i + 1) % nums.size()]){
                dip++;
            }
        }
        if(dip <= 1){
            return true;
        }
        return false;
    }
};