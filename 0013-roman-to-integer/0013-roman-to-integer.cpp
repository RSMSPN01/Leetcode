// Approach : It is straight forward, we will traverse from the back side if the
// next value is smaller it means we have to subtract if not then keep on adding
// the values and return the final result
class Solution {
public:
    int romanToInt(string s) {
        // helping map to store character and values
        unordered_map<char, int> romanVal;
        romanVal.insert({'I',1});
        romanVal.insert({'V',5});
        romanVal.insert({'X',10});
        romanVal.insert({'L',50});
        romanVal.insert({'C',100});
        romanVal.insert({'D',500});
        romanVal.insert({'M',1000});
        int n = s.length();
        // store the value of last roman char
        int totalSum = romanVal[s[n-1]];
        for (int i = n-2; i >=0; i--) {
            if(romanVal[s[i]] >= romanVal[s[i+1]]) {
                // means current value is greater so simply add 
                totalSum += romanVal[s[i]];
            }else {
                // value is smaller subtract it
                totalSum -= romanVal[s[i]];
            }
        }
        return totalSum;   
    }
};