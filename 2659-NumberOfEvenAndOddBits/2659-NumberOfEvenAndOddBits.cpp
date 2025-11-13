// Last updated: 11/13/2025, 1:14:20 PM
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int>arr(2,0);
        int evenCount = 0;
        int oddCount = 0;
        int bitCount = 0;
        while(n>0){
            if(bitCount%2==0 && n&1){
                evenCount++;
            }else if(n&1){
                oddCount++;
            }
            bitCount++;
            n>>=1;
        }
        arr[0]=evenCount;
        arr[1]=oddCount;
        return arr;
    }
};