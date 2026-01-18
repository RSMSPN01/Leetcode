// Approach : Naive way could be search in linear way and can return the index element 

// Efficient Approach : We can use the fact that there will we different elements at both
// the sides of a particular index is different so we can choose our search space based 
// on that thing 

// Also keep in mind that first and last element of the array can't be the peak elements
// so we can skip them as we go on for searching.

// so the test cases were not that clear to me so i failed the code now i get to know that
// even the last and firt element could be the peak, by consedering the fact that all the 
// elements outside the array on index < 0 and index >=n well we smaller so first and last
// elements could also be the peak wooow?
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // handle edge cases
        if(n == 1){
            return 0;
        }
        if(n == 2){
            if(nums[0]<nums[1]){
                return 1;
            }
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int start = 1,end = n-2, mid = 0;
        while(start <= end) {
            mid = start + (end - start)/2;
            // i was trying to handle the first and last conditon inside the loop
            // what why? when i can directly handle them outside.

            // if(mid == 0 && nums[mid] > nums[mid +1]){
            //     //edge case to handle
            //     return mid;
            // }
            // if(mid == n-1 && nums[mid] > nums[mid -1]){
            //     return mid;
            // }

            if(nums[mid] > nums[mid-1] && nums[mid]> nums[mid+1]){
                return mid;
            }
            else if(nums[mid+1] > nums[mid]){
                // search in the right side
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        // if no peak then return 0
        return 0;
    }
};