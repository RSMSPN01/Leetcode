// Approach : i am thinking to use two loops in this, frist loop will decide the
// current index, lets say i am standing at i index, i will then run a loop from
// i to arr[i] indexes to find out the maximum out of those, then i will jump to
// that index and keep going T.C =>  O(n^2)

// My approach is quardatic int nature, it has a simple constant solution which
// i miss totally bcs of the fact i was purely thinking about using greedy

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // better code from solution two pointers
        int n = nums.size();
        int goal = n-1; 
        for(int i = n -2;i>=0;i--){
            if(i + nums[i] >= goal){
                goal = i; // updte the new goal index
            }
        }
        return goal==0; // check if we have reached to first indx or not


        // brute approach (quardatic time)
        // int n = nums.size();
        // int i = 0;
        // while (i < n) {
        //     if (i + nums[i] >= n - 1) {
        //         // can we jump directly out from current index
        //         return true;
        //     }
        //     int maxVal = 0;
        //     int maxIndx = -1;
        //     for (int j = i + 1; j <= i + nums[i];
        //          j++) { // search for the biggest value
        //         if (nums[j] >=
        //             maxVal) { // use equal too bcs we need the most last maxvalues in case duplicate exists
        //             maxVal = nums[j];
        //             maxIndx = j;
        //         }
        //     }
        //     if (maxIndx == -1) {
        //         return false; // we no greater value found means we can't jump
        //     }
        //     i = maxIndx; // else update the curnt jump with max
        // }
        // return false;
    }
};