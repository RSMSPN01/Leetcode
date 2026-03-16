// First Approach : I though we need to find out all the substrings of the
// string and check if there is any valid palindrome i was not able to
// understand the question

// The question is we need to do the partition of the strings and based on that
// we need to find the palindrome, this pattern is new to me

// The approach is used from strivers video, look if you feel stuck

class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(string& s, vector<vector<string>>& ans, vector<string>& temp, int ind) {
        if (ind == s.length()) {
            // base case means partition reach to end
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < s.length(); i++) {
            // if substring is palindrome then only go ahead
            string tempStr = s.substr(ind, i - ind + 1);
            if (isPalindrome(tempStr)) {
                temp.push_back(tempStr);
                helper(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        helper(s, result, temp, 0);
        return result;
    }
};