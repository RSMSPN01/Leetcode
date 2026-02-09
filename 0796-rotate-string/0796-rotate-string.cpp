class Solution {
public:
    bool rotateString(string s, string goal) {
        // the logic behind this question is well explained in the editorial
        // itself we can even KMP algorithm but instead will just use the trick
        if(s.length() != goal.length()) {
            return false;
        }
        string result = s + s;
        return (result.find(goal) != string::npos ? true : false);
    }
};