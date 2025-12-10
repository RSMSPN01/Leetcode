// Last updated: 12/10/2025, 11:46:37 AM
#include <bits/stdc++.h>
class Solution {
public:
// Approach : So i do know there exists a better approach then this to move zeros but i am going to 
// use the very naive way but this is not good at all because this is array but in real world those
// may be connected to further LL or something else so by this way it is not going to work
// Naive way
// step 1: count and erase all the zeros from the vector
// step 2: Then run a loop from the back and put zeros there
// note that this is not a good approach 
    void moveZeroes(vector<int>& nums) {
        int totalZeros = 0;
        while(find(nums.begin(),nums.end(),0) != nums.end()){ // have a look for the find function
            // it means find all the zeros till all the zeros gets finsihed
            auto it = find(nums.begin(),nums.end(),0); // store the index where is 0 in the array
            nums.erase(it); // erase the first zero from the vector.
            totalZeros++;
        }
        // Now we have removed the array by using the erase function the size of the vector is also
        // reduced so we will simply push back the left zeros till count becomes 0.
        while(totalZeros){
            nums.push_back(0);
            totalZeros--;
        }
    }
};