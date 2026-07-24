// I don't know how people has done using sorting, either sort them both first
// and then check but i believe that could produce wrong results

// Approach 1 : I was thinking earlier to produce all permutations and then
// check, but the problem is in each single step i need to constantly compare
// the values.

// Approach 2 : I know this is sliding window problem so i will maintain s1 size
// window and keep the track of the frequencies too in s2 and compare then in
// constant time, i think thats the most optimal approach.
class Solution {
public:
    bool compareFreq(string& s1, vector<int> freq) {
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']--;
            if (freq[s1[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int k = n;
        vector<int> freq(26, 0); 
        int left = 0, right = 0;
        while (right < m) {
            freq[s2[right] - 'a']++;
            int curnWindow = right - left + 1;
            if (curnWindow > k) {
                freq[s2[left] - 'a']--;
                left++;
            }
            if (compareFreq(s1, freq)) {
                return true;
            }
            right++;
        }
        return false;
    }
};