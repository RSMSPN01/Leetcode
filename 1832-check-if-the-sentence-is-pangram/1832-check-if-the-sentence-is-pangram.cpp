class Solution {
public:
    bool checkIfPangram(string sentence) {
        // check if size of sentence is 26
        int n = sentence.length();
        if (n < 26) {
            return false;
        }
        // now keep the frequency track
        vector<int> freq(26, -1);
        for (int i = 0; i < n; i++) {
            freq[sentence[i] - 'a']++;
        }
        // now check if we miss any value
        for (int i : freq) {
            if (i == -1) {
                return false;
            }
        }
        return true;
    }
};