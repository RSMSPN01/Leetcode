// The extreme naive appraoch could be to pick one a substring at a time and
// calculate the unique values in it further optimization could be that once a
// repeating character is found don't search further just break from there and
// move to next character

// The worst time complextiy for this is O(n^3), lets see some help maybe i will
// improve this a little bit more
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using two pointer and array from striver video
        int n = s.length();
        int left = 0;
        int right = 0;
        vector<int> hash(256, -1);
        int maxLength = 0;
        while (right < n) {
            if (hash[s[right]] != -1) {
                // it means i have seen this earlier
                if (hash[s[right]] >= left) {
                    // see if the value is in between the left to right or not
                    // if yes then imedietealy update the curnt value of left
                    left =
                        hash[s[right]] + 1; // move it by one step from earlier
                }
            }
            int length = right - left + 1;
            maxLength = max(maxLength, length);
            // now update the current value index
            hash[s[right]] = right;
            right++;
        }
        return maxLength;
    }
};