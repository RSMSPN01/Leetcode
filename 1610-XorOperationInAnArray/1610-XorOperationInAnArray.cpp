// Last updated: 11/13/2025, 1:14:21 PM
class Solution {
public:
    int xorOperation(int n, int start) {
        int count = 0;
        for(int i = 0;i<n;i++){
            count ^= start+2 * i; 
        }
        return count;
    }
};