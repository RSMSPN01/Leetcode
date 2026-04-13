// Niave Approach : I can create a map in which i can store the pre computed
// result for each of element in the second array, so that when call is made we
// directly get the answers Time.C = O(n^2), Space.C = O(n)

// i can't think of any better solution then the naive one
// how the hell i am going to use stack here, i have no clue

// This is the question of montonic stack

// We will maintain a stack decreasing stack so that we can get the result for
// any particular value in just one operation

// We just take an extra map to store the result so fetching will be constant
// else everything is same as the striver video of NGE

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // this will help is fetching the value in constant Time
        unordered_map<int, int>map(nums2.size());
        stack<int> decrease;
        // we will traverse the array backward
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // maintaining the decreasing order
            while (!decrease.empty() && nums2[i] >= decrease.top()) {
                decrease.pop();
            }
            if (!decrease.empty()) {
                // stack will always have the NGE at top
                // so map it with the current value
                map.insert({nums2[i], decrease.top()});
                // map[nums2[i]] = decrease.top(); // this will also work
               
            } else {
                // and if stack empty store -1
                map.insert({nums2[i], -1});
            }
            // push the current value
            decrease.push(nums2[i]);
        }
        // return the answer as a vector
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            // fetch the values from the map
            result[i] = map[nums1[i]];
        }
        return result;
    }
};