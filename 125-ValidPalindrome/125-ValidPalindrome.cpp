// Last updated: 11/13/2025, 1:15:41 PM
#include <cctype>
class Solution {
public:
    bool checkString(string& str, int i, int j) {
        if (i == j || i > j && str[i] == str[j]) {
            return true;
        }
        if (i < j && str[i] == str[j]) {
            return checkString(str, ++i, --j);
        }
        return false;
    }
    bool isPalindrome(string s) {
        if (s.length() == 1) {
            return true;
        }
        // string s;
        // for (char ch : result) {
        //     if (isalnum(ch)) {
        //         s += tolower(ch);
        //     }
        // }
        // int i = 0, j = s.length() - 1;
        // while (i < j) {
        //     if (s[i] != s[j]) {
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;
        string str;
        for (char& i : s) {
            if (isalnum(i)) {
                str += tolower(i);
            }
        }
        if(str.length() == 0 || str.length() ==1){
            return true;
        }
        return checkString(str, 0, str.length() - 1);
    }
};