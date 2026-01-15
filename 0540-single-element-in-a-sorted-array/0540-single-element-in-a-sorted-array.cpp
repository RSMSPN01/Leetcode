// Naive approach : By linear searching the very next element or by using XOR operation on this 
// both will provide the same answers but it will cost us O(n) time

// Better Approach : We know there exists an element which appears only once it means we have 
// an array with odd size and we can take advantage of that, we will search that side which 
// have total odd elements.

// So i am going with this theory, that if no. is odd or even and based on that i will choose
// the search space next which side to search for
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // edge case
        if(nums.size() == 1){
            return nums[0];
        }
        int start = 0, end = nums.size() - 1, mid = 0;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(mid == 0 || mid == nums.size() - 1){
                // extra check so it won't give false result of mid - 1 or mid + 1.
                return nums[mid];
            }
            if(nums[mid] != nums[mid -1] && nums[mid] != nums[mid +1]){
                // if found such number then simply return that number.
                return nums[mid];
            }
            else if(mid & 1) {
                // it means mid value is odd and previous value is also the same then 
                // move to the other side
                if(nums[mid] == nums[mid - 1]){
                    start = mid + 1;
                }else {
                    end = mid -1;
                }
            }else{
                // now if it even then check
                if(nums[mid] == nums[mid - 1]) {
                    end = mid -1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};