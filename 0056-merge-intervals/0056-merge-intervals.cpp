// Appraoch : So i can see that we are going to use some type of sorting
// here,then we have to check the second and first element are overlapping or
// not if they are overlapping then we will merge them (lets first write the
// code in your own way).
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        // it will sort on the bases of first element not on the second
        sort(intervals.begin(), intervals.end());
        // push the very first value inside result to take reference
        result.push_back({intervals[0][0], intervals[0][1]});
        int k = 0; // to keep track of the result vector indexes
        for (int i = 1; i < intervals.size(); i++) {
            // start from one bcs we have already checked for the 0'th element
            if(result[k][1] >= intervals[i][0]){
                // it means second element is greater then first so update it
                result[k][1] = max(result[k][1],intervals[i][1]);
                // use max here bcs there could be a lesser value in the second element
            }else{
                // if not means these are not overlapping
                // directly push it into the result vector
                result.push_back({intervals[i][0],intervals[i][1]});
                k++;
            }
        }
        return result;
    }
};