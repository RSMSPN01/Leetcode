// Last updated: 11/13/2025, 1:15:52 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), count = 0, flag = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] == ' ' || i == -1) && flag) {
                return count;
            } else {
                if (s[i] != ' ') {
                    flag = 1;
                    count++;
                }
            }
        }
        return count;
    }
};