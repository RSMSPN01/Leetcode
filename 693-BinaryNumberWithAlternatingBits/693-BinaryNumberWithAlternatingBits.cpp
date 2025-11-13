// Last updated: 11/13/2025, 1:14:43 PM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n>0 && n>1){
            if((n&1)^((n>>1)&1)){
                n>>=1;
            }else{
                return false;
            }
        }
        return true;
    }
};