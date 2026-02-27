// Now this question is same as the previous question, only difference is i
// don't need duplicate and i guess that can be handled using sorting itself bcs
// i think it will not take duplicates if i sort it

// So sorting must be done to get the desired output and i think i should you
// hash set to avoid the duplicate lets see is there any better way to solve the
// problem or can use find function as well but it is going to take extra time
// too.

// so i have also find out a little different way to solve the problem now i am
// going to follow that approach so that the code looks more clean and industry
// level readable code

class Solution {
public:
    void helper(vector<int>& v, int target, vector<vector<int>>& result,
                vector<int>& temp, int ind) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = ind; i < v.size(); i++) {
            if (i > ind && v[i] == v[i - 1]) {
                continue;
            }
            if(v[i] > target) {
                break;
            }
            temp.push_back(v[i]);
            helper(v, target - v[i], result, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        helper(candidates, target, result, temp,0);
        return result;
    }
};