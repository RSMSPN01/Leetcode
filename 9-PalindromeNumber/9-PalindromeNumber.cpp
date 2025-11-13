// Last updated: 11/13/2025, 1:16:08 PM
class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x;
        long long rem = 0;
        long long result = 0;
        if(x<0){
            return false;
        }
        while (x != 0) {
            rem = x%10;
            x = x/10;
            result = result*10+rem;

        }
        if(temp == result){
            return true;
        }else{
            return false;
        }
    }
};