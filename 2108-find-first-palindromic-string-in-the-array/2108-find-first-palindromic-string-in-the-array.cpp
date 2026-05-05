class Solution {
public:
    bool isPalindrome(string& str) {
        int low = 0;
        int high = str.length() - 1;
        while (low < high) {
            if (str[low] != str[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (isPalindrome(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};