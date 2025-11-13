// Last updated: 11/13/2025, 1:14:59 PM
class Solution {
public:
    bool isVowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
            x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        if (n == 0 || n == 1) {
            return s;
        }
        int i = -1, j = n;
        while (true) {
            do {
                i++;
            } while (!isVowel(s[i]) && i<n-1);
            do {
                j--;
            } while (!isVowel(s[j]) && j>0);
            if (i >= j) {
                return s;
            }
            swap(s[i], s[j]); // further improvement is this if letters are same then don't swap
        }
        return s;
    }
};