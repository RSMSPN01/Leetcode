// Approach : first calculate the prefix sum till we have values in sequence
// and then look if the sum we calculate is already there or not if it is there
// then we need to find the next greater element which is not present there and
// return that

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> values;
        // we need set so that we can search for values in constant time
        for (int i : nums) {
            values.insert(i);
        }
        int currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 == nums[i - 1]) {
                // only add values if they are in sequence
                currSum += nums[i];
            } else {
                break;
            }
        }
        // now search for the value in the set
        while (values.find(currSum) != values.end()) {
            // if have found the value search for the next value
            currSum++;
            // look for the next greater
        }
        // in the end we will have the next largest value which is not present
        return currSum;
    }
};