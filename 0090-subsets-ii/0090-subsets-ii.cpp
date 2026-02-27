// Naive Approach : Find all the subsets, using bitmask or recursion and while
// inserting them inside the result check if they exists or not in the result

// Better Approach : Check before creating the subset that it should not start
// the search from the previous same element

class Solution {
public:
    void help(vector<int>& nums,vector<vector<int>>& ans,vector<int> & temp,int ind) {
        for (int i = ind; i < nums.size(); i++) {
            if(i > ind && nums[i] == nums[i-1] ) {
                // already have a subset created of the same number 
                continue;
            }
            temp.push_back(nums[i]);
            ans.push_back(temp);
            help(nums,ans,temp,i+1);
            temp.pop_back();
        }   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sorting is must to continue with this Approach
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>temp;
        // push empty thing first
        result.push_back(temp);
        help(nums,result,temp,0);
        return result;
    }
};