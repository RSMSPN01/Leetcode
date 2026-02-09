// Approach : A two pointer approach can be used here to solve the problem in
// which i will find empty space and when i will found one i will just reverse
// from there

// Only problem is how to handle blank spaces in the string either i have to
// check it before hand before doing actuall thing i don't have idea about that

class Solution {
public:
    void removeSpaces(string& s) {
        // this function handles to remove spaces
        // remove spaces from the front of string
        int i = 0;
        while (isspace(s[i])) {
            i++;
        }
        s.erase(0, i);
        // from the end of the string

        int j = s.length() - 1;
        while (isspace(s[j])) {
            j--;
        }
        s.erase(j + 1);

        // from the middle of the string
        // if two spaces are together then remove them only keep one
        int k = 1;
        while (k < s.length()) {
            if (isspace(s[k]) && isspace(s[k - 1])) {
                s.erase(k, 1);
            } else {
                k++;
            }
        }
        // wrong way to remove space from the midddle
        // int low = 0;
        // int high = 0;
        // while (low < s.length()) {
        //     while ((s[high] != ' ') && (s[high] != '\0')) {
        //         high++;
        //     }
        //     if (s[high] != '\0') {
        //         high++;
        //         int count = high;
        //         while (isspace(s[high])) {
        //             high++;
        //         }
        //         s.erase(count, high - count);
        //     }
        //     low = high;
        // }
    }
    void reverse(string& s, int i, int j) {
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        removeSpaces(s);
        int i = 0, j = 0;
        // traverse on string using two pointer
        while (i < s.length()) {
            while (s[j] != ' ' && s[j] != '\0') {
                j++;
            }
            // find blank space and reverse the string from there
            reverse(s, i, j - 1);
            j++;
            i = j;
        }
        // fully reverse the string
        reverse(s, 0, s.length() - 1);
        return s;
    }
};