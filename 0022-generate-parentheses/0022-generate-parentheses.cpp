// Approach : I know how to create all the possible combinations, but don't know
// how to create a perfect one means it should have both '(' and ')'
// Lets see some help
// Naive Approach : Get all the possible parenthesis and check if they are well
// formed or not but that take one extra function to check

// Better Approach : We know from n we can have 2*n size parenthesis, and in
// that both open and close should have equal count to n, so we use them to
// eliminate extra search time

class Solution {
public:
    void helperFun(int n ,vector<string>& result, string curn, int openCount, int closeCount) {
        if(curn.length() == 2* n) {
            result.push_back(curn);
            return;
        }
        // now include it first
        if(openCount < n) {
            helperFun(n,result,curn + '(',openCount+1,closeCount);
        }
        // we are not removing anything here bcs we never hardcorded
        // any value into the variable 
        if(closeCount < n && closeCount < openCount ) {
            helperFun(n,result,curn +')',openCount,closeCount + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helperFun(n,result, "", 0, 0);
        return result;
    }
};