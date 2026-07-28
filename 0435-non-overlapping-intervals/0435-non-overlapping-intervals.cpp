// Approach : This is my first question of greedy never tried any of these
// questions before, so i don't have any idea how to solve it i took help

// So in this approach we first sort the values but by passing custom comparator
// this time we sort using the smaller end time, and then compare the current
// ending time to the next starting time

// Greedy doesn't always give the right answer but if it works in here that is
// good , and the reason why this work is that we need to finish the task early
// so that we can keep on doing more task so we sort them using the end time
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        // sort based on end time
        int n = intervals.size();
        int count = 1; // first is always valid that is why start loop from 2
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[prev][1] <= intervals[i][0]) {
                count++;
                prev = i;
            }
        }
        return n - count;
    }
};