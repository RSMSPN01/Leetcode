// Approach : This is the first time i am solving this kind of problem sorting
// plus binary search

// step 1 : sort the arrays based on the starting point
// step 2 : them apply b.s and check what are the intersecting points

// T.C = O(nlogN)

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        long long ans = 0;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n - 1; i++) {
            int endTime = intervals[i][1];
            // search for other intervals in which end time is greater then
            // start time and to search efficiently we will use b.s on the start
            // time as it is sorted already

            int low = i + 1;
            int high = n - 1;
            int mid = low + (high - low) / 2;
            while(low <= high) {
                mid = low + (high - low) / 2;
                if (intervals[mid][0] <= endTime) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += high - i;
        }
        return ans;
    }
};