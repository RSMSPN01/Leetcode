class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // count frequency
        vector<int> freq(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<int> result;
        int maxFreq = -1;
        while (maxFreq != 0) {
            for (int i = 1; i <= 100; i++) {
                if (freq[i] > 0) {
                    result.push_back(i);
                    freq[i]--;
                }
                // check is there any value freq greater then 0 if not break
            }
            maxFreq = *max_element(freq.begin(), freq.end());
        }
        // overall time complexity is n + (100 * 100) = n.
        return result;
    }
};