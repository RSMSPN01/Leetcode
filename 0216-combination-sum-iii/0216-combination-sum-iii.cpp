// Approach : The whole idea is the same as the previous questions only
// difference this time is how to implement the value of i is different here

// Both the Approach are covered recursive and iterative

class Solution {
public:
    // recursive function call
    // void helper(vector < vector < int >> & ans, vector < int > & temp, int i,
    // int k, int target) {
    //     if (i > 10) {
    //         return;
    //     }
    //     if (temp.size() > k ) {
    //         return;
    //     }
    //     if(target < 0) {
    //         return;
    //     }
    //     if(temp.size() == k && target == 0) {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     temp.push_back(i);
    //     helper(ans,temp, i + 1, k,target - i );
    //     temp.pop_back();
    //     helper(ans,temp, i + 1, k,target);
    // }

    // iterative function which is more clean
    void helper(vector<vector<int>>& ans, vector<int>& temp, int ind, int k, int target) {
        if (temp.size() == k && target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < 10; i++) {
            if (i > target) {
                // doesn't make sense to check ahead;
                break;
            }
            if (temp.size() > k) {
                break;
            }
            temp.push_back(i);
            helper(ans, temp, i + 1, k, target - i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // handle the edge case here only
        if (k >= n) {
            return {};
        }
        vector<int> temp;
        vector<vector<int>> result;
        helper(result, temp, 1, k, n);
        return result;
    }
};