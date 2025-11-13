// Last updated: 11/13/2025, 1:14:50 PM
class Solution {
public:
    int findComplement(int num) {
        if(num ==1){
            return 0;
        }
        int res = 0;
        int i = 0;
        while(num>0){
            int bit = num&1;
            num>>=1;
            res = res |(!bit<<i);
            i++;
        }
        return res;
    }
};