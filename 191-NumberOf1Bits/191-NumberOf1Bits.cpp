// Last updated: 11/13/2025, 1:15:27 PM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            n = n &(n-1);
            count++;
        }
        return count;
    }
};