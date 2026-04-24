// Approach : So there is no brute force approach to this question, i have an
// intiution from CSWM video, so i am going to apply that here

// Total Sum = minSum + maxSum
// so we can easily calculate the total sum and min sum
// so to calculate max = Total sum - minSum , that is it
// min sum will be calculated using the kadanes algo

// so there will be two cases in this in first case we will get the
// solution by using simply kadanes algo and another case will when we get the
// max sum in circular way, so we will find both of them and return it.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // maxSum = totalSum - minSum;
        // calculate total sum here
        int totalSum = 0;
        for (int i : nums) {
            totalSum += i;
        }

        // calculate min sum here
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int currMinSum = 0;
        int currMaxSum = 0;
        for (int i : nums) {
            currMinSum += i;
            currMaxSum += i;
            minSum = min(currMinSum, minSum); // atleast one value should be there
            maxSum = max(currMaxSum, maxSum);
            if (currMaxSum < 0) {
                currMaxSum = 0; // reset it
            }
            if (currMinSum > 0) {
                currMinSum = 0; // reset the values
            }
        }
        // if the whole array is already negative and we don't check it here we
        // will end up getting the wrong answer lets say whole array is -ve so
        // total sum will be already the minimum and we calculate the min sum
        // which will also we the minimum and when we subtract total-minSum we
        // will get zero and that will be false bcs we need the max of array and
        // that max must be a value which is lesser then zero
        if (maxSum < 0) {
            return maxSum;
        }
        // calculate the circular max sum here
        int circularMax = totalSum - minSum;

        return max(maxSum, circularMax);
    }
};