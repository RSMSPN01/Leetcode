// Niave Appraoch : Run three loops and continously check for the answer.
// Time C = O(n^3) and Space C = O(1)

// Better Appraoch : Using hash map, but we have to create new map in each
// iterations i.e if n = 5 then we have to create map 5 times
// Time C = O(n^2) and Space C = O(n)

// Optimal Appraoch : Same Appraoch we use to solve 2 sum using two pointer
// But this time we, will make one element constant and use two pointer to
// find other two elements
// Time C = O(nlogn X n^2) and Space C = O(1)
// Formula Used = i+j+k = 0, we have i so, j+k = -1, j & k will be found using
// two pointer
// The code is working but i am not able to come up with any logic to handle the
// duplicates triplets in edge cases like [0,0,0,0,0]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // This is also a kind of two pointer approach but it also 
            // keep track of duplicates as well.
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // here j and k are moved in such a way that they will
                    // not repeat the duplicates values again
                    while (j< k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j< k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        } 
        return result;

        // So i was making a little mistake here, i am using the logic which i
        // have learn from the course, but in this way only work if there are
        // all unique values but fails in the case that we don't need duplicates
        // values for that we have to use a total different approach here.

        // vector<int> twoSum(vector<int>& nums, int i) {
        //     int sum = -nums[i];
        //     int low = i + 1, high = nums.size() - 1;
        //     while (low < high) {
        //         if (nums[low] + nums[high] == sum) {
        //             return {-sum, nums[low], nums[high]};
        //         } else if (nums[low] + nums[high] > sum) {
        //             high--;
        //         } else {
        //             low++;
        //         }
        //     }
        //     return {};
        // }
        // vector<vector<int>> threeSum(vector<int>& nums) {
        //     vector<vector<int>> result;
        //     sort(nums.begin(), nums.end());
        //     // sort two apply two pointer here
        //     for (int i = 0; i < nums.size() - 2; i++) {
        //         vector<int> temp = twoSum(nums, i);
        //         if (!temp.empty()) {
        //             // if not empty then push the values
        //             result.push_back(temp);
        //         }
        //     }
        //     return result;
    }
};