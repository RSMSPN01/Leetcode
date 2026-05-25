// This is same as the previous question only one difference is there the way
// left pointer is going to move, i am not able to think of or i will store the
// index of the last seen so that on that basis i can directly move the left
// pointer

// the moving of the pointer is same as the previous one no change at all
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;  // helps us to decide wheter we should take or not
        int k = 2; // always constant
        int n = fruits.size();
        int left = 0, right = 0;
        int maxFruits = 0;
        while (right < n) {
            if (freq.size() > k) {
                // we can't take this window reduce it first
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    // if zero then remove it from here
                    freq.erase(fruits[left]);
                }
                left++;
            }
            // keep pushing the current fruit
            freq[fruits[right]]++;
            if (freq.size() <= k) {
                maxFruits = max(maxFruits, right - left + 1);
            }
            right++;
        }
        return maxFruits;
    }
};