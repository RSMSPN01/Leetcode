// Last updated: 11/13/2025, 1:14:54 PM
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str(n);
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
                str[i]="FizzBuzz";
            } else if ((i + 1) % 3 == 0) {
                str[i]="Fizz";
            } else if ((i + 1) % 5 == 0) {
                str[i]="Buzz";
            } else {
                str[i]=to_string(i + 1);
            }
        }
        return str;
    }
};