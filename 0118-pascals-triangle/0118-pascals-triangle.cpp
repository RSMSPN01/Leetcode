// Approach : I tried this question but i was not able to think of any of the
// Solution not even the brute force so i watch video and i have explained about
// this question in detail in the notes have a look there how the code is
// actually working hint - (just pure mathematics).
class Solution {
public:
vector<int> generateRow(int row) {
    vector<int> result;
    result.push_back(1);
    int ans = 1;
    for(int i = 1;i<row;i++){
        ans = ans * (row - i);
        ans = ans / i;
        result.push_back(ans);
    }
    return result;
}
    vector<vector<int>> generate(int numRows) {
        // result vector and one is already there.
        vector<vector<int>> result;
        // in each row number of elements in each row is equal to row itself.
        for (int i = 1; i <= numRows; i++) {
            result.push_back(generateRow(i));
            }
            return result;
        }
};