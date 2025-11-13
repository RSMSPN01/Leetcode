// Last updated: 11/13/2025, 1:14:56 PM
class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0;
        int j = 0;
        char c = 0 ;
        while (i < s.length() || j < t.length()) {
            c ^= s[i++] ^ t[j++];
        }
        return c;
    }
};