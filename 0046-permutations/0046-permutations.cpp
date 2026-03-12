// So there are two ways to solve the problem first using extra space and
// another without space

class Solution {
public:
    // using bactrack and extra space
    // Approach : Is similiar to take or not take but only difference we take
    // extra space to store the values which are already taken and can't be use
    // further in the tree.

    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans,
                vector<bool>& map) {
        // base is simple if size reach max store it
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        // value of i start from 0 everytime, rather then current index
        for (int i = 0; i < nums.size(); i++) {
            if (map[i]) {
                // if true means we can take current element
                temp.push_back(nums[i]);
                // make it false bcs we have used it once
                map[i] = false;
                // call the function
                helper(nums, temp, ans, map);
                // remove it
                temp.pop_back();
                // make it true again so used again
                map[i] = true;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> map(nums.size(), true);
        helper(nums, temp, result, map);
        return result;
    }
};