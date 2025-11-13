// Last updated: 11/13/2025, 1:15:25 PM
class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7){
            return true;
        }
        if(n<10){
            return false;
        }
       int digit = log10(n)+1;
       int final = 0;
       for(int i =0;i<digit;i++){
        final += (n%10)*(n%10);
        n/=10;
       }
       if(final==1){
        return true;
       }else{
        return isHappy(final);
       }
    }
};