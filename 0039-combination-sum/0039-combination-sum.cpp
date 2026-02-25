// Approach : I do get the rough idea that how the tree is going to look like
// for this question but to implement it is a tough job, how to actually write
// code that is i have to look for

// I thought that i have to use loop in this to solve the problem,but i was
// wrong to be honest i don't have any idea how my brain could find the Solution
// by its own i don't have to do, i think a little and i got the result in my
// mind i apply it and got the result, have to check it back so that i could
// understand the working of the pattern

// Approach is same as take or not but this time we keep on taking the number 
// itself first then move for other reuslts.
class Solution {
public:
    void helper(vector<int>& v,vector<int> temp, vector<vector<int>>& r, int i,int t,int s) {
        if(i == v.size()) {
            return;
        }
        if(s == t) {
            // result found stop
            r.push_back(temp);
            return;
        }
        if(s > t) {
            // going wrong side come back
            return;
        }
        temp.push_back(v[i]);
        // search further in i index first then move ahead
        helper(v,temp,r,i,t,s+v[i]);
        temp.pop_back();
        helper(v,temp,r,i+1,t,s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        helper(candidates,{},result,0,target,0);
        return result;
    }
};