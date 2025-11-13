// Last updated: 11/13/2025, 1:14:51 PM
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int count = 0;
        while(n){
            n = n&(n-1);
            count++;
        }
        return count;
    }
};