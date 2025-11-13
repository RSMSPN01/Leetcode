// Last updated: 11/13/2025, 1:15:04 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){return false;}
        if(n==1){return true;}
        while(n>1){
            if(n%3){return false;}
            else{n/=3;}
        }
        return true;
    }
};