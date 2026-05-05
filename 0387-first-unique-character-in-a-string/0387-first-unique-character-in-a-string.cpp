class Solution {
public:
    int firstUniqChar(string s) {
        // first keep the frequency of the string
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        // now see if any character have a single freq then return
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};