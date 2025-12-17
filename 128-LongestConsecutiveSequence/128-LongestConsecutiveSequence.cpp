// Last updated: 12/18/2025, 3:49:49 AM
class Solution {
public:
    // Brute Approach : By sorting the whole array and then continously check
    // for the next element if the next element is same then update the count
    // and keep going till the end   T.C = O(Nlogn) S.C = O(1)
    // But this appraoch fails the condition that we need to solve the question
    // in linear time approach

    // Better Approach : Using extra hash table
    int longestConsecutive(vector<int>& nums) {
        // Naive way to solve the problem
        if (nums.size() == 0) {
            return 0;
        }
        // using sort function

        // sort(nums.begin(), nums.end());
        // int count = 1, maxCount = 1;
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] != nums[i - 1]) {
        //         if (nums[i] - 1 == nums[i - 1]) {
        //             count++;
        //             maxCount = max(maxCount, count);
        //         } else {
        //             count = 1;
        //         }
        //     }
        // }
        // return maxCount;

        // Better way to do this 
        unordered_set<int> freqTable(nums.begin(),nums.end());
        // all the values are pushed into the table.
        // for (int i = 0; i < nums.size(); i++) {
        //     table.insert(nums[i]);
        // }
        int count = 1;
        int maxCount = 1;
        // now we can either check for all the numbers like is there greater no.
        // available then that if yes then keep on counting that or else we can
        // start from a number which is valid it will help us to save the time 
        // and total no. of operations.

        // first check for valid number
        // valid number - we check if is there exists a number smaller then the 
        // current one if yes it we can't start from there 
        // so our goal is to find a number of which there exists no less number 
        // then that 
        for (int i : freqTable ) {
            if(freqTable.find(i-1) == freqTable.end()){
                // it means it is a valid number from where we can start the search
                int temp = i+1;
                while(freqTable.find(temp) != freqTable.end()){
                    count++;
                    temp += 1; // check for the just next element
                }
            maxCount = max(maxCount, count);
            count = 1;
            }
        }
        return maxCount;
    }
};