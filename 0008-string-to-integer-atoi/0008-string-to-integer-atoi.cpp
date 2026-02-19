// Already solved the question using iterative method in strings module but now
// using different way (recursion) to solve it
// Approach : just thinking to convert the loop into recursion
class Solution {
public:
    int normalizedValue(string& s, int i, long long result, int sign) {
        int n = s.length();
        int digit = s[i] - '0';
        if (i >= n || !isdigit(s[i])) {
            return sign * result;
        }
        if(result > (INT_MAX - digit) / 10) {
            if(sign == -1) {
                return INT_MIN;
            }
            return INT_MAX;
        }
        result = result * 10 + digit;
        return normalizedValue(s,i+1,result,sign);

    }
    int myAtoi(string s) {
        // so defaul sign is sent as positive
        // so what was i doing earlier was i was trying to traverse the whole
        // string in the function above which makes the whole code very complex
        // instead we will do some precomputation work here and then call the
        // function which just reduced the work done.
        int n = s.length();
        int i = 0;
        // skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        int sign = 1; // 1 means +ve
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        return normalizedValue(s, i, 0, sign);
    }
};