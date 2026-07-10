1class Solution {
2public:
3    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4        unordered_map<int, int> freq;
5        for (int i = 0; i < nums1.size(); i++) {
6            freq[nums1[i]]++;
7        }
8        unordered_set<int> result;
9        for (int i = 0; i < nums2.size(); i++) {
10            if (freq.find(nums2[i]) != freq.end()) {
11                result.insert(nums2[i]);
12            }
13        }
14        vector<int> ans;
15        for (auto i : result) {
16            ans.push_back(i);
17        }
18        return ans;
19    }
20};