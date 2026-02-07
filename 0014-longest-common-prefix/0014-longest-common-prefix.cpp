// Approach : So i am thinking the string as a two array but instead of
// traveling row wise we will traverse from the column side. The time complexity
// is going to be O(n^2) but lets see if there exists any better Solution then
// this or not after solving with this Approach

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs[0].length(); i++) { // column loop
            char match = strs[0][i]; // char to match with
            for (int j = 1; j < strs.size(); j++) { // row loop 
                // but first check even the size of the string is
                // valid or not
                if( i < strs[j].length()) {
                    if(strs[j][i] != match){
                        return result;
                    }
                }else{
                    return result;
                }
            }
            // if string is matched then attach it 
            result += match;   
        }
        return result;   
    }
};