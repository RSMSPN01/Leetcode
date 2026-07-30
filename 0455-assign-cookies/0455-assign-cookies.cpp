// Approach : I am thinking to sort both of these arrays and then use two
// pointer on them and constantly check compare the size in both if it is
// smaller or equal i will move ahead
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort both to get the max answer
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};