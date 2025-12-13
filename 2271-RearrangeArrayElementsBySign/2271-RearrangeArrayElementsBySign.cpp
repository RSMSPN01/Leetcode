// Last updated: 12/14/2025, 5:06:14 AM
class Solution {
public:
    // Approach : I solve a similar question in linked list as well in which we
    // need to move the even and odd indexes this is similar too.

    // We are going to use two pointer approach for this where one pointer stays
    // at even index and one at odd, we will use indexes to check is it at its
    // correct position or not.

    // logic i am thinking is if i found a -ve no. i will swap it with the -ve
    // indx but the problem is what if there is already a -ve no present in the
    // -ve indx that will create mess

    // or i can think in this way rather then thinking for both +ve and -ve just
    // do and move all +ve or -ve one of them to thier correct location rest
    // will be set by itself.

    // or there is another way count what +ve no is it like if it is 1st then it
    // should go to 0 index if 2nd then go to 2 if 3rd go to 4th index and same
    // for negative too.

    // I look for the hint and find out that i need to divide the array but by
    // taking extra space it is so easy but the problem is how to do that in
    // place that is the final point for this thing.

    // although i waster so many hours in this question by thinking that this is
    // going to be solve in-place i know different ways how not to solve the
    // pro- blem. The code is easy as hell mate, just take extra space and solve
    // it.
    vector<int> rearrangeArray(vector<int>& nums) {
        // What i was thinking then just left half bcs i realize that i was
        // doing something wrong it is going to work for some very edge cases
        // but majority will not work here

        // // edge case to handle
        // if(nums.size() == 2){
        //     // it means that first element is -ve and size is two just swap
        //     if(nums[0] == <0){
        //     swap(nums[0],nums[1]);
        //     }
        //     return nums;
        // }
        // int positive = 0;
        // int negitive = 1;
        // for(int i = 0;i<nums.size();i++){
        // }
        // The optimal approach for this
        vector<int> ans(nums.size(), 0);
        int pos = 0, neg = 1; // two pointers to keep track
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) { // if found no less then place at even index
                ans[pos] = nums[i];
                pos += 2; // increment by 2 steps for each 
            } else { // else place at odd index 
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans; // and just return the modified vector
    }
};