// Approach : I am thinking to solve this question just like the previous
// classical questions of sliding window, lets see am i right or not
class Solution {
public:
    bool patrnFound(vector<int>& cF, vector<int> pF) {
        // constant function to find pattern
        for (int i = 0; i < 256; i++) {
            if (pF[i] > 0 && cF[i] < pF[i]) { // valid char and freq check
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string result = "";
        int n = s.length();
        int m = t.length();
        if (m > n) {
            return result;
        }
        int patternLength = INT_MAX;
        int right = 0, left = 0;
        vector<int> p_freq(256, 0); // for constant calculation
        vector<int> currnFreq(256, 0);
        for (char c : t) {
            p_freq[c]++;
        }
        while (right < n) {
            currnFreq[s[right]]++;
            if (patrnFound(currnFreq, p_freq)) {
                // once pattern found keep reducing from left
                while (left <= right && patrnFound(currnFreq, p_freq)) {
                    // remove from the left
                    currnFreq[s[left]]--;
                    left++;
                }
                string temp = "";
                temp += s.substr(left - 1, right - left + 2);
                if (temp.length() < patternLength) {
                    patternLength = temp.length();
                    result = temp;
                }
            }
            right++;
        }
        return result;
    }
};