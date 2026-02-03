// Naive Approach : create a new array where you stored the values of both the
// arrays in sorted order and then if the size is odd return the center element
// if not then add two and return.
// Time.C = O(n), Space.C = O(n)

// Better Approach : Both the arrays are already sorted so we can think towards
// binary search. The logic behind the b.s is quite tricky to be honest lets see
// what can we got

// so basically here we don't acutally apply the bs directly on the array itself
// but instead we apply on the size and we don't acutally divide the arrays into
// two part it is just for our imagination so that it is easy to understand
// i need to revise this question again and again so that the i get to know
// about the pattern
//      ---overview---
//      l1 | r1(mid1)
//      l2 | r2(mid2)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we first need to apply the search on the smaller array
        // to further reduce the time taken
        int n1 = nums1.size() , n2 = nums2.size() ;
        if (n2 < n1) {
            findMedianSortedArrays(nums2, nums1);
        }
            // so these elements should be on the leftSide
            // except that all will go to other side
            int leftSide = (n1 + n2 + 1) / 2;
            bool isEven = false;
            ((n1 + n2) % 2 == 0) ? isEven = true : isEven = false;
            int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
            // now these variables keep the track so that we get
            // rough idea about the division of arrays
            double low = 0, high = n1, mid1 = 0, mid2 = 0;
            while (low <= high) {
                // so this is the mid of the first array
                mid1 = low + (high - low) / 2;
                // mid1 is pointing after the no of elements in
                // the left side if leftSide we take 3 elements from the
                // nums1 then leftSide will point to index 4 just after leftSide
                // now mid2 will point where use your brain if we need 5
                // elements in total and mid1 = 2 means we need three extra
                // elements to the left side so point the mid2 there.
                mid2 = leftSide - mid1;
                // now there can be edge cases where division of array in such a
                // way that it can lead to memory error so we have to handle it
                (mid1 == 0) ? l1 = INT_MIN : l1 = nums1[mid1 - 1];
                (mid2 == 0) ? l2 = INT_MIN : l2 = nums2[mid2 - 1];
                (mid1 == n1) ? r1 = INT_MAX : r1 = nums1[mid1];
                (mid2 == n2) ? r2 = INT_MAX : r2 = nums2[mid2];
                // now just simply compare easiest part
                if (l1 <= r2 && l2 <= r1) {
                    // if even then return the average or just return the center
                    if (isEven) {
                        return (double)(max(l1, l2) + min(r1, r2)) / 2;
                    }
                    return max(l1, l2);
                } else if (l1 > r2) {
                    high = mid1 - 1;
                } else {
                    low = mid1 + 1;
                }
            }
        
        return 0;
    }
};