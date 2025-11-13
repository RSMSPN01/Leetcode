// Last updated: 11/13/2025, 1:15:07 PM
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
    while (i < n)
    {
        if (arr[i] < 0)
        {
            i++;
        } else {
            if (arr[arr[i]] >= 0)
            {
                int index = arr[i];
                arr[i] = arr[index];
                arr[index] = -1;
            } else {
                return arr[i];
            }
        }
    }
    return -1;
    }
};