// Approach : I am not be able to think of any single approach to solve the
// problem not even the naive way to be honest
// Lets look for some hints and editorial and then try this

// Intution : Count that either we are inside a nested bracket or not if we
// are then store it if not then do nothing.

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int counter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                counter++;
                // how to check we are inside multiple parentheses
                // if counter is 2 it means we are inside
                if (counter >= 2) {
                    // if we are inside then update the result
                    result += '(';
                }
            }
            if (s[i] == ')') {
                counter--;
                if (counter >= 1) {
                    result += ')';
                }
            }
        }
        return result;
    }
};