// Naive Approach : Traverse the string and count the braces and store the
// maximum value of the count.
class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxCount = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};