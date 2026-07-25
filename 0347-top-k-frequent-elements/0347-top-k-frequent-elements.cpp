// Appraoch : So i am thinking to use hash map, keep on counting the frequency
// and updating the max frequency, in the end pop out all the values with max
// frequency . Time O(n+n) space O(n)

// I don't have any idea about how to use heap in this question, lets seek some
// help though

// A further optimization could be to use bucket sort in this one for constant
// time
typedef pair<int, int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // First create a map and store the freq
        unordered_map<int, int> freq;
        for (int val : nums) {
            freq[val]++;
        }
        // Put all the values in the maxHeap and sort them on the basis of freq
        // not key
        // so instead of maxheap we can minHeap as further optimization to solve
        // the problem in O(nlogk) t.c
        // priority_queue<pair<int, int>> maxHeap;
        // for (auto it : freq) {
        //     maxHeap.push({it.second, it.first});
        // }
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        for (auto it : freq) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop();
                // help reduce time complexity
            }
        }

        // pop the value and store if it.second is >= k
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};