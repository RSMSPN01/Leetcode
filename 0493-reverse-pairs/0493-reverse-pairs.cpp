// Naive Approach : Using two for loops and comparing each element one by one
// and keep counting if condtion becomes true
// Time.C = O(n^2), Space.C = O(1)

// Better Approach : It is a merge sort pattern, where a[i] > a[j] and i < j
// similiar to count inversions. Now instead of checking from the front side
// we will check from the back so that we don't loose the elements which make
// a successfull pair

// i was making a mistake in which i was comparing i with zero how many times
// i have to tell myself that i need to compare with low not zero it just took 2
// hours to fix and chatgpt fix that in the end and the logic which i was
// thinking for reverse comparing doesn't work well it will miss some
// comparisions

class Solution {
public:
    int inversions = 0;
    void countPairs(vector<int>& nums, int low, int high) {
        // we create this extra function even changes can be done directly in
        // the code also but it is a good practice
        int mid = low + (high - low) / 2;
        // so we have to compare here before the actual sorting
        // so we will traverse the right half and check how many of them
        // can form a pair if they can then we will add them but we don't use
        // double loops here but a smarter way to do so
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            // it will not add the value twice but can done in a single
            // iteration
            while (right <= high && nums[i] > 2 * (long)nums[right]) {
                right++;
            }
            // add the total count here
            // it will give the final total ans
            inversions += right - (mid + 1);
        }
    }
    // copied merge sort code
    // now i am going to apply the hints here by reading the hints i am going to
    // solve this using code from the striver series
    void merge(vector<int>& nums, int low, int high) {
        int mid = (low + high) / 2;
        int n = high - low + 1;
        int temp[n];
        int i = low;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= high) {
            temp[k++] = nums[j++];
        }

        for (int l = 0; l < n; l++) {
            nums[low + l] = temp[l];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            // this is the extra function which we are using we can even use
            // this in inversion code as well but in that code there are very
            // less lines of code to change so we didn't use there
            countPairs(nums, low, high);
            merge(nums, low, high);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return inversions;
    }
};