// I can understand the graph or the flow of this, means how we are selecting
// the characters but i am not be able to write code for that, lets see some
// help and i will try this again by myself

class Solution {
public:
    void helper(string& d, unordered_map<char, string>& key,
                vector<string>& ans, vector<string>& curr, int indx) {
        if (indx >= d.length()) {
            string temp = "";
            for (auto& s : curr) {
                temp += s;
            }
            ans.push_back(temp);
            // ans.push_back(curr);
            return;
        }
        int k = d[indx];
        string temp = key[k];
        for (int i = 0; i < temp.length(); i++) {
            curr.push_back(string(1,temp[i]));
            helper(d, key, ans, curr, indx + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> keys = {
            {'1', ""},     {'2', "abc"}, {'3', "def"},
            {'4', "ghi"},  {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> result;
        vector<string> curr;
        helper(digits, keys, result, curr, 0);
        return result;
    }
};