// Approach : Using stack here is no brainer, push if it is opening bracket and
// push if closing bracket but check they should both match i.e of same type
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                // add opening brackets
                brackets.push(s[i]);
            } else if (s[i] == ')') {
                // check is there match
                if (!brackets.empty() && brackets.top() == '(') {
                    brackets.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (!brackets.empty() && brackets.top() == '{') {
                    brackets.pop();
                } else {
                    return false;
                }
            } else {
                if (!brackets.empty() && brackets.top() == '[') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        // in end also check stack is empty or not, if empty means we have got
        // all the pairs in the right order 
        return brackets.empty();
    }
};