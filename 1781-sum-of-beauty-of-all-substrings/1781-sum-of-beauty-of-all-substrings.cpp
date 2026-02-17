// Brute Approach : Find all the substrings and count the difference between
// them using two loops and by checking freq difference between them Time.C =
// O(n^2*k), Space.C = O(k)    where k = 26

// Better Approach : Actually there exists no better Approach then this only
// improvement which can we done is that we can Actually reduce the T.C by k
// time means totoal of Time.C = O(n^2), Space.C = O(k)

class Solution {
public:
    int differenceCount(string& s) {
        int n = s.length();
        int freq[26] = {0};
        int maxCount = INT_MIN;
        int minCount = INT_MAX;
        // update max and min both in single loop
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int k = 0; k < 26; k++) {
            if (freq[k] > 0) {
                maxCount = max(maxCount, freq[k]);
                minCount = min(minCount, freq[k]);
            }
        }
        // if max and min count are different then only send difference
        return (maxCount != minCount) ? maxCount - minCount : 0;
    }
    int beautySum(string s) {
        int n = s.length();
        int maxSum = 0;
        // generate all substrings
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                string temp = s.substr(i,j-i+1);
                maxSum += differenceCount(temp);
            }
        }
        return maxSum;
    }
};