// Last updated: 12/15/2025, 12:34:45 PM
class Solution {
public:
// Approach : To be hones i don't know is this going to work or not i don't
// have any idea all about these lexography and all but i notice a pattern
// here maybe i could we wrong but lets try that then i will move ahead

// Here i notice 3 patterns :
// 1: Array is fully sorted : Then just swap the last two values
// 2: Array is descend sorted : Reverse the whole array then too
// 3: Array has a dip : If a number is smaller then previous move that no
// to the last

// Let's apply these and see what will happen 

// I Try these but i found out that the 3rd step is not that direct step
// as 1 and 2 there are many different conditions i need to check before
// sending the smaller number to the back maybe there is a further smaller
// number present then it should go there but if there are two smaller
// no then they both should go in different ways there are actually many 
// possibilites not just on i am thnking about.

    void nextPermutation(vector<int>& nums) {
        // edge cases 
        // if(nums.size() == 0|| nums.size() ==1){
        //     return;
        // }
        // // create two flags to handle the sort
        // bool ascendSort = true;
        // bool descendSort = true;
        // for(int i =1;i<nums.size();i++){
        //     // first check for is array sorted in ascending order
        //     if(ascendSort){ // if true then go ahead and check further
        //         if(nums[i-1]>nums[i]){
        //             // at any point the condition doesn't satisy make it
        //             // false
        //             ascendSort = false;
        //         }
        //     }
        //     if(descendSort){
        //         // same as above
        //         if(nums[i-1]<nums[i]){
        //             descendSort = false;
        //         }
        //     }
        //     // now handle the last case when we saw a dip in the array
        //     if(nums[i]<nums[i-1]){
        //         // it means we have found the dip now start moving all 
        //         // elements by one position back.

        //         // there is no one way to handle this case there can be
        //         // many possible cases of solve this particular thing 
        //         // like swaping of two no.'s together and many more.
        //     }
        // }
        // if(ascendSort){
        //     swap(nums[nums.size()-1],nums[nums.size()-2]);
        // }
        // if(descendSort){
        //     reverse(nums.begin(),nums.end());
        // }   

        // Better way to solve the problem
        // using inbuilt stl library function
        // it will change the nums to the next permutation itself
        // next_permutation(nums.begin(),nums.end());

        // Most optimal way to solve the problem
        // Explained in notes too
        // step 1: Find out the dip in the array
        int index = -1;
        for(int i = nums.size()-2;i>=0 ;i--){
            if(nums[i]<nums[i+1]){
                index = i; // Store the index where we find the dip
                break;
            }
        }
        // edge case handle 
        // it means the array is sorted in decreasing order
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // Find out the next greater element which is greater then the current 
        // element but not the most greatest but the next greater element
        // look notes for better understanding
        for(int i = nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        // now reverse the array from the next index where there has a dip
        reverse(nums.begin()+index+1,nums.end());
    }
};