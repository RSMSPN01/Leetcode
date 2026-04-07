// Approach : Reverse the string first till index k and keep the other half as
// it is that is it i guess
// We can do in different ways like first reverse the string till index k then
// attach the left out half with it
// or we can simply use inbuilt function reverse by giving the end value as
// s.begin()+k so that it only reverse the string till k-1 indexes

class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.length();
        if (k == 1) {
            return s;
        }
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};