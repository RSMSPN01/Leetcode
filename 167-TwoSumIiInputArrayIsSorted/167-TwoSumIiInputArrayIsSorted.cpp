// Last updated: 11/13/2025, 1:15:33 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> input(2, 0);
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                input[0]= i+1,input[1] = j+1;
                return input;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return input;
    }
};