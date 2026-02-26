class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, n = haystack.size(), m = needle.size();
        int temp = 0;
        while (i < n) {
            j = 0;
            if (haystack[i] == needle[j]) {
                temp = i;
                // if match go ahead and search
                while (j < m && haystack[i] == needle[j]) {
                    i++;
                    j++;
                }
                if (j == m) {
                    return i - m;
                }
                i = temp + 1;
            } else {
                i++;
            }
        }
        return -1;
    }
};