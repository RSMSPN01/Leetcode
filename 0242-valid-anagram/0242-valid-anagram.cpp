class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if (n != m) {
            return false;
        }
        int freq[256] = {0};
        for (int i = 0; i < n; i++) {
            freq[s[i] - '0']++;
        }
        for (int i = 0; i < m; i++) {
            freq[t[i] - '0']--;
            if (freq[t[i] - '0'] < 0) {
                return false;
            }
        }
        return true;
    }
};