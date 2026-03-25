class Solution {
public:
    int count = 0;
    void merge(vector<int>& arr, int low, int high) {
        int mid = (low + high) / 2;
        int n = high - low + 1;
        int temp[n];
        // int i = low;
        // int j = mid + 1;
        int k = 0;

        int i = mid;
        int j = high;
        while (i >= low && j >= mid + 1) {
            if (arr[i] > (long)2 * arr[j]) {
                count += j - (mid + 1) + 1;
                i--;
            } else {
                j--;
            }
        }
        i = low;
        j = mid + 1;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {

                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int l = 0; l < n; l++) {
            arr[low + l] = temp[l];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, high);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};