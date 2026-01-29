// Niave Approach : Run two loop and store the largest value

// Better Approach : Using hashMap, we can keep the track but have to handle
// zeros in some way, i was wrong for this approach, if we have to only take
// continous subbarray then why we even need a map we can do this question as
// kadane's algo

// i have write two different codes for this approaches have a look at both of
// them and try to find out what mistake i was doing there.

// using kadane's algo helped me to pass somewhat around 150 cases but after
// that it just fails i think we are going to use that same approach to solve
// the whole problem but a little bit modified version of it.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // the actuall code was so fucking simple man, don't use kadane's also
        // here bcs the kadanes algo which people actually use not the actuall
        // one it is kind of that prefix sufix way and people are saying it
        // kadane's algo it is very hard to implement and edge cases are way to
        // much using the one from the striver video looks notes for observation

        int prefix = 1;
        int suffix = 1;
        int maxPro = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - 1 - i];
            maxPro = max(maxPro, max(prefix, suffix));
        }
        return maxPro;
        // int possibleMax = nums[0];
        // why this loop? this loop will handle all the test cases for
        // [-2,6], [0,0,0], [0,0,0,1] etc like these
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] > possibleMax) {
        //         possibleMax = nums[i];
        //     }
        // }
        // if (possibleMax == 0) {
        //     // it means all the elements are already zero in the array.
        //     return 0;
        // }
        // int tempPro = nums[0];
        // int maxPro = nums[0];
        // if (tempPro == 0) {
        //     tempPro = 1;
        // }
        // for (int i = 1; i < nums.size(); i++) {
        //     tempPro = tempPro * nums[i];

        //     if (tempPro > maxPro) {
        //         maxPro = tempPro;
        //     }
        // }
        // now compare between two max
        // if (maxPro > possibleMax) {
        //     return maxPro;
        // }
        // return possibleMax;

        // in this approach i try to treat zero as one, so that i can get the
        // maximum output but i pass around 150 cases and now it is giving me
        // error again this is the best i could possibly think of.

        // if (nums.size() == 1 && nums[0] != 0) {
        //     return nums[0];
        // }
        // int maxPoss = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] > maxPoss) {
        //         maxPoss = nums[i];
        //     }
        // }
        // int maxPro = INT_MIN;
        // int temp = 1;
        // for (int i = 0; i < nums.size(); i++) {
        //     temp = nums[i] * temp;
        //     maxPro = max(maxPro, temp);
        //     if (nums[i] == 0) {
        //         // again reset
        //         temp = 1;
        //     }
        // }
        // if (maxPro < 0) {
        //     return 0;
        // }
        // return (maxPro > maxPoss ? maxPro : maxPoss);
    }
};