// Naive Approach : Traverse the string from the front and keep doing the
// following checks while traversing if any of the if else condition fail
// return the result. (This is what i am going to do)
// I have directly applied if else in the this, what is asked in
// the question i converted that into if/else code

class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        long long result = 0;
        bool isNegative = false;
        bool isSpace = false;
        bool sign = false;
        bool isZero = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                // we have space check even we have encountered any
                // sign or zero till now
                if (sign || isZero || result>0) {
                    break;
                }
                isSpace = true;
            } else if (s[i] == '+' || s[i] == '-') {
                // sign is occured check have there any zeros before
                if (isZero || sign || result>0) {
                    // also check isn't there are multiple signs together
                    break;
                }
                if (s[i] == '-') {
                    isNegative = true;
                }
                sign = true;
                if (result != 0 && sign) {
                    // it means sign is again appeared in between somewhere
                    return result;
                }
            } else if (s[i] == 48) {
                // check it is leading zero or a zero b/w numbers
                if (result == 0) {
                    isZero = true;
                } else {
                    // it is b/w no.s zero so attach it to the resutl
                    if (result >= INT_MAX / 10) {
                        return (isNegative)?INT_MIN:INT_MAX;
                    }
                    result = result * 10 + 0;
                }
            } else if (s[i] >= 49 && s[i] <= 57) {
                // you got a valid digit store it now
                result = result * 10 + s[i] - '0';
            } else {
                // any word encountered stop imediately there
                break;
            }
        }
        // round it off to a valid value before returning it
        if (result > INT_MAX) {
            if (isNegative) {
                result = INT_MIN;
            } else {
                result = INT_MAX;
            }
        }
        return (isNegative) ? -result : result;
    }
};