class Solution {
public:
    string toLowerCase(string s) {
        string result;
        for (int i = 0; i < s.length(); i++) {
            result += tolower(s[i]);
        }
        return result;
    }
};