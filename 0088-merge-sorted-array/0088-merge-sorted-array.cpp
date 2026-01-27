// Naive Appraoch : It is the same appraoch i have used for my previous
// submission in which i have taken extra space and store the result back into
// the nums1 array.

// Better Appraoch : The instructions are not clear in the question but we have
// to solve this question inplace without any extra space required. So i will
// use two pointers and when i will find out that the position of an element is
// wrong then i will place it to its correct location this is the most niave way
// i could poissibly think of lets try that first and see will that work or not

// so i am trying to run a loop on the largest array and placing each value of
// the second array to its correct location this is the appraoch i am using.

// insertition sort can be used but again, it will take nlogn time
// Shell sorting is also a way to solve the problem you can look the code online
// I am going to use the same methond that striver told me

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // striver way to sovle the problem
        // Appraoch : First put the values at the correct array then sort them
        // individually after sorting both the arrays, combine them in one
        // array.
        int i = m - 1, j = 0;
        while ((i >= 0 && j < n) && nums1[i] > nums2[j]) {
            // put the vlaues to correct array 
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }
        // then sort both the arrays but till begin + m
        // bcs last n values are going to be zero so don't touch them
        sort(nums1.begin(),nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        // put the second array back to the first array
        for (int k = 0; k < n; k++) {
            nums1[k + m] = nums2[k];
        }

        // most stupid way to think like this, this code fails for literally
        // every test cases except for the one in which there is only one
        // overlapping value other then that it fails for every single test
        // case. idk what i think for suc kind of logics

        // if (n == 0)
        //     return;
        // int i = 0, j = 0;
        // while (i < m) {
        //     if (nums1[i] <= nums2[j]) {
        //         i++;
        //     } else {
        //         // nums1[i] is not at it's correct position so move it
        //         int temp = nums1[i];
        //         while (nums2[j] < temp) {
        //             nums1[i] = nums2[j];
        //             i++;
        //             j++;
        //         }
        //         // put temp back to correct location
        //         nums1[i] = temp;
        //     }
        // }
        // while (j < n) {
        //     // if any values left then directly push them inside the nums1.
        //     i++;
        //     nums1[i] = nums2[j];
        //     j++;
        // }

        // code from striver's video
    }
};