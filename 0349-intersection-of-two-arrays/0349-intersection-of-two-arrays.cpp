class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }
        unordered_set<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (freq.find(nums2[i]) != freq.end()) {
                result.insert(nums2[i]);
            }
        }
        vector<int> ans;
        for (auto i : result) {
            ans.push_back(i);
        }
        return ans;
    }
};