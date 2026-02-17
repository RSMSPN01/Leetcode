// Niave Approach : Run two loops and continously pass the string to check is it
// palindrome or not
// Time.C = O(n^3), Space.C = O(1)

// I am not be able to think for any optimal Solution lets see some help
// so i am going to use a better solution over here which is expanding corners
// Time.C = O(n^2), Space.C = O(n)

// I was finding the substring based on even or odd lenght of the total string,
// instead i need to check for that from a particular place either it can be odd
// or even length of substring

class Solution {
public:
    string validPalindrome(string& s, int i, int j) {
        int n = s.length();
        while (i >= 0 && j < n && (s[i] == s[j])) {
            i--;
            j++;
        }
        return (s.substr(i + 1, j - i - 1));
    }
    string longestPalindrome(string s) {

        // this normal code works good for odd length and
        // we have to do an extra check for even length too
        // string ans = s.substr(0, 1);
        // if (!(n & 1)) {
        //     int i = n / 2;
        //     int j = i - 1;
        //     while (i >= 0 && j < n && (s[i] == s[j])) {
        //         i--;
        //         j++;
        //     }
        // result = s.substr(i + 1, j - i - 1);
        // if(result.length() > ans.length()) {
        //     ans = result;
        // }
        // }
        // start from one and go till second last bcs
        // one element is always a palindrome

        int n = s.length();
        string result = "";
        for (int i = 0; i < n; i++) {
            // odd will start from its curent location
            string odd = validPalindrome(s, i, i);
            // even start from itself and just next
            string even = validPalindrome(s, i, i + 1);
            if (odd.length() > result.length()) {
                result = odd;
            }
            if (even.length() > result.length()) {
                result = even;
            }
        }
        return result;
    }
};