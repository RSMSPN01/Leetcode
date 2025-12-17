// Last updated: 12/18/2025, 3:49:24 AM
class Solution {
public:
    // Brute Force : So we run nested loops and we keep on adding the values one
    // by one till we get the value k T.C = O(n^2)

    // Better Approach : So we sort the array first and then we are going to use
    // the two pointer approach for this T.C = O(nlogN + N)

    // Optimal Approach : Take extra hash set and do it as same the longest
    // subarray sum we did for the previous question T.C = O(N) and S.C = O(N)

    // just a little correction in the approach that we need to take hash map
    // instead of set because when there are negatives in the array it doesn't
    // count that how many times before that no. (preSum-k) exists and instead
    // just incrementing the count we increment the freq of that particular no.

    int subarraySum(vector<int>& nums, int k) {
        // need to store the prefix sum
        // unordered_set<int> prefix;
        unordered_map<int,int> prefix;
        int count = 0;
        int preSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // we don't need to explicitly check for this it will we handled in
            // the hash map itself .
            // if(nums[i] == k){
            //     count++;
            // }
            preSum += nums[i];
            if (preSum == k) {
                count++;
            }
            if (prefix.find(preSum - k) != prefix.end()) {
                count += prefix[preSum-k];
            }
            prefix[preSum]++;
        }
        return count;
    }
};