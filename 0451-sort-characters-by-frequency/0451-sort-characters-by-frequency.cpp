// Naive Approach : Using map freq of all the characters are stored, then map is
// sorted using a custom operator which will first sort on the bases of
// frequency and then on ascii characters.
// Time.C = O(nlogn), Space.C = O(n)

// Better Approach : I look for others code they have used pair here bcs it is
// easy to store and sort the data but the most optimal way to solve this
// problem is using bucket sort

// Intution : Each bucket will store the freq of the string how many times each
// string is repeated
// bkt[freq[i]] += char(i); / here we are storing the string
// together in the bucket based on thier freq please dry run this to understand
// what is actually happening here.

// for (char c : bkt[i]) result.append(i, c); why this loop so we have a string 
// in the bkt eg - 'ac' i need to traverse through that so this can be also done
// using this way bkt[i][j] but to write more clean code we do this 
// append fun() i will tell how many time to append the value of C
// append(freq, value)


class Solution {
public:
    string frequencySort(string s) {
        // total 26 + 26 + 10 // only this much to store
        vector<int> freq(128, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }
        // make bucket to store
        // max value of bucket could be the size of the string
        vector<string> bkt(n + 1); // n+1 bcs index start from 1
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                // push string according to freq
                bkt[freq[i]] += char(i);
            }
        }
        string result = "";
        for (int i = n; i > 0; i--) {
            for (char c : bkt[i]) {
                result.append(i, c);
            }
        }
        return result;
    }
};