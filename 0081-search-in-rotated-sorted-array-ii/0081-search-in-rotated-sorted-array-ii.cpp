// Approach : So i have used the same approach as the similar question of this one checking direct
// for the sorted and usorted part but the problem is some of the test cases like for eg- 1011111
// now in this case no matter what we do we will get stuck and will not be able to find the zero
// bcs in bs we search for which search space we will choose to move ahead but in this case both
// the search spaces will not be true.

// So i was doing in the previous task is that i am checking the search space based on the low,mid
// and high which is causing the error eg - 10111 in this low mid and high all will be the same 
// so what i will do i can just short the overall array bcs i know that if all these are same and
// all of them are not equal to target it means that they are not even required here so lets remo-
// ve them from the array.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // same code as the normal search rotate
        int start = 0, end = nums.size() - 1, mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return true;
            }else if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                // This is the extra condition here which is added 
                // if we don't need them just remove them 
                start = start + 1;
                end = end - 1;
                continue;
                // why continue bcs there may we chances that there may be some other values
                // in the array with same low, mid and high
            } 
            else if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};