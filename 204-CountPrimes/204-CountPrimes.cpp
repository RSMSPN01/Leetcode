// Last updated: 12/5/2025, 10:19:03 AM
class Solution {
public:
    // Approach : there is no direct approach for this question as what i think
    // i read this
    // topic as theory and i have the idea from there how to solve it using an
    // extra space array\ and i am going to use that on the first place maybe
    // there is an efficient solution available for this i will look that after
    // once i solve this.
    int countPrimes(int n) {
        vector<bool> v(n, true); // take an array of size n and fill that with
                                 // all true values.
        // edge cases to handle.
        if (n == 0 || n == 1) {
            return 0;
        }
        // run a loop till sqrt of n why? becs if there is a number which is
        // present after the sqrt of n it will handled in the second loop itself
        // when all the factors of the number is marked as false.
        int count =
            0; // to count all the false values which appears in the array.
        for (int i = 2; i * i <= n;
             i++) { // start from 2 because 0 and 1 are already handled
            if (v[i] == true) { // if element is true then move to its factor.
                int temp = i;
                while ((temp + i) < n) { // first check if it even exists in the array or not
                    temp = temp + i; // only move to the factors of the i value
        // and also check it is already visited or not by checking the bool value
                    if (v[temp] == true) {
                        v[temp] = false; // make all the values false
                        count++; // count all the false values in the vector.
                    }
                }
            }
        }
        // if we subtract the false values from the total values then we will
        // get all the true values.
        int finalCount = n - count - 2;
        // total count - false count - first two values 0 and 1.
        return finalCount;
    }
};