// Approach : So there are only 256 char which we have to check so we can keep
// the track of every char and if at any point the char doesn't match to the
// previously stored char then we can return false
// Time.C = O(n + n), Space.C = O(1) or O(256 + 256)

// The logic which i have used here is good when we have only check for one
// direction means the s[i] is correctly maped to g[i] or not but it will not
// check vise versa it fails to check in unidirectional

// So i need to check from both the sides of the string that either they are
// maped to each other or not.
// This code fails becuase of the fact that there are special character as well
// and if i do '0' subtraction from the stirng it might give me values in
// negative , so to avoid it typecast it directly
// s[i] - '0' will give out of bound result
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Now this whole question can be solved in one traversal also
        int n = s.length();
        int m = t.length();
        if (n != m) {
            return false;
        }
        char map1[256] = {0};
        char map2[256] = {0};
       
        for (int i = 0; i < n; i++) {
            if (map1[s[i]] == 0 && map2[t[i]] == 0) {
                // it means both are not yet assigned
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            } else {
                // check if both points to same value or not
                if (map1[s[i]] != t[i] || map2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
        // checking from the first side s string side
        // empty array to track values

        // char freq[256] = {0};
        // for (int i = 0; i < s.length(); i++) {

        //     if (freq[(int)s[i]] == 0) {
        //         // if it is empty store it
        //         // freq[s[i] - '0'] = t[i];
        //         freq[(int)s[i] ] = t[i];

        //     } else {
        //         // if not, check if pointing to same value or not
        //         if (freq[(int)s[i]] != t[i]) {
        //             return false;
        //         }
        //     }
        // }
        // // checking from the t string side
        // char freq2[256] = {0};
        // for (int i = 0; i < t.length(); i++) {

        //     if (freq2[(int)t[i] ] == 0) {
        //         // if it is empty store it
        //         freq2[(int)t[i] ] = s[i];
        //     } else {
        //         // if not, check if pointing to same value or not
        //         if (freq2[(int)t[i] ] != s[i]) {
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
};