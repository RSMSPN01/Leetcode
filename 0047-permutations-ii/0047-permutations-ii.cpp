// Approach : I am going to use the swapping approach here which is a
// backtracking approach but not use extra space
// It is same as the permutation 1 question just one extra check that is It
// Solving same pattern problem with different approaches don't make any sense
// stick to one approach and master it.

// we need to maintain a map for storing the frequency of the values, so that we
// don't ended up taking same number twice

class Solution {
public:
    // same code from permutation 1
    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans,
                unordered_map<int, int>& freq) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        // this approach is wrong we can't do it this way, rather then
        // traversing on indexs we need to traverse on unique element

        // for (int i = 0; i < nums.size(); i++) {
        //     if (freq[nums[i]] > 0) {
        //         // check if freq is more then 0, if yes then take the element
        //         temp.push_back(nums[i]);
        //         freq[nums[i]]--;
        //         helper(nums, temp, ans, freq);
        //         temp.pop_back();
        //         freq[nums[i]]++;
        //     }
        // }

        // run loop on unique freq count not on indexes
        for (auto& [value, count] : freq) {
            if (count == 0) {
                continue;
            }
            // do backtracking now
            temp.push_back(value);
            freq[value]--;
            helper(nums, temp, ans, freq);
            temp.pop_back();
            freq[value]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        // instead of bool vector we will use map for frequency
        // vector<bool> map(nums.size(), true);
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        helper(nums, temp, result, freq);
        return result;
    }
};