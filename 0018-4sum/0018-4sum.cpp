// Naive Appraoch : Run four loops together and just stop whenever you get the
// answer, but that way take a lot of time so we avoid that writting

// Optimal Approach : Similar as two sum and three sum, for this we need to have
// know about 3 sum problem, we will use that same exact code but this time just
// use one more loop to take that extra variable as constant.
// T.C = O(n^4) and S.C = O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // edge cases to handle
        if(nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {continue;}
            // update the targe value
            int tempTarget = target - nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {continue;}
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long long sum = (long long)nums[j] + nums[k] + nums[l];
                    if (sum == tempTarget) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) {k++;}
                        while (k < l && nums[l] == nums[l + 1]) {l--;}

                    } else if (sum > tempTarget) {l--;}
                    else {k++;}
                }
            }
        }
        return result;
    }
};