// I know this is a sliding problem, i also know we have to choose a substring,
// but the real problem which i am not able to solve is how do we choose to
// which character to be changed or replace

// So i found that at most we can pick only 2 letters at a time and keep
// checking if the frequency of both the characters exceeds the limit then k
// times.

// so my thinking is right but every time checking the frequency is a costly
// operation and we can do that faster usign direct formula maxLength -
// maxFrequency

// The question is kind of same to the previous one but still needs more
// practice to get better at these kinds of pattern
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), maxFreq = 0, left = 0, right = 0;
        int maxLength = 0;
        vector<int> hash(26, 0);
        while (right < n) {
            hash[s[right] - 'A']++; // update the freq
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            // check if current window is even valid or not
            if ((right - left + 1) - maxFreq > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            // keep in mind that we never update the freq back again
            // bcs changing the freq is not dependent on the answer
            if ((right - left + 1) - maxFreq <= k) {
                maxLength = max(maxLength, (right - left + 1));
            }
            right++;
        }
        return maxLength;
    }
};