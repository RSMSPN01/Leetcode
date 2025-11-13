// Last updated: 11/13/2025, 1:14:12 PM
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool>freq(26,false);
        for(int i =0;i<s.length();i++){
            if(freq[s[i]-'a']){
                return s[i];
            }
            else{
                freq[s[i]-'a'] = true;
            }
        }
        return ' ';
    }
};