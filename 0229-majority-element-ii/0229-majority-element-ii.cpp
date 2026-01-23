// Approach : Naive way could be by using extra space for storing all the
// elements which are greater then n/3.

// Better Approach: Kadan,s algo it states that if an element is in majority it
// will remain in majority after making any changes i am thinking to use that
// but only problem here is of two or more elements are greater then how can we
// return both of them without using any extra space

// i don't think so there is way to solve the problem without using hash table -
// we can push each value in hash and count there occurence together in the same
// loop

// we know that for sure the majority element could not be more then 2 elements
// bcs lets say n = 8 so n/3 = 8/3 = 2, it means to be majority and element must
// be greater then 2 times so it means 3 times and 3 * 3 = 9 > n so there is
// only 2 elements TC-O(n) and SC O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // So it is a slight modified version of moore's algo
        // we just need to maintain one more varaible for the second
        // just one more condition is needed new here else same as moore
        int n = nums.size();
        int count1 = 0, count2 = 0, element1 = 0, element2 = 0;
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && element2 != nums[i]) {
                // then update the current value
                element1 = nums[i];
                count1 = 1; // in this algo we also do this too
            } else if (count2 == 0 && element1 != nums[i]) {
                element2 = nums[i];
                count2 = 1;
            } else if (nums[i] == element1) {
                count1++;
            } else if (nums[i] == element2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        // verify it one more time 
        int occr1 = 0,occr2 = 0;
        // if (element2<element1) {
        //     swap(element1,element2);
        // }
        for (int i = 0; i < n; i++) {
            if(nums[i] == element1) {
                occr1++;
            }else if(nums[i] == element2) {
                occr2++;
            }
        }
        vector<int> result;
        if(occr1 > n/3 ) {
            result.push_back(element1);
        }
        if(occr2 > n/3) {
            result.push_back(element2);
        }
        return result;
        
        // using extra space to sort the things
        // just an extra check is needed to check that the last element should
        // not be same.

        // unordered_map<int, int> freq;
        // vector<int> result;
        // for (int i = 0; i < nums.size(); i++) {
        //     freq[nums[i]]++;
        //     if ((freq[nums[i]] > nums.size() / 3)) {
        //         if(result.empty()){
        //             // if empty push directly into it
        //         result.push_back(nums[i]);
        //         }else if(result.back() != nums[i]){
        //             // if not empty then further check that it should not be
        //             the duplicate
        //            result.push_back(nums[i]);
        //         }
        //     }
        //     if(result.size() == 2) {
        //         break;
        //     }
        // }
        // return result;
    }
};