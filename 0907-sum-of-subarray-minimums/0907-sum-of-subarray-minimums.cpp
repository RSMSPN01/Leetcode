// Naive Approach : Get all the subbarrays one by one and keep on counting the
// minimum of it and keep on adding it, it will take O(n^2/) time so that is not
// most optimal way

// Better Approach : It is somewhat like finding the next samller element, i am
// not be able to think of any approach i should look for some help now

// So we need to count the number of frequency of each element, that how many
// times a number is needed in the final sum, we calculate the frequency of each
// value then multiply it with the current value and add that to total sum

// for any index we calculate the previous smaller or equal element and next
// smaller element to the right multiply them both and add to final result

// we basically calculate that a value is how much time is minimum in the
// subbarray and we calculate the next samller to left and right that is it

// watch striver video for better understanding, it is easy just look for video
// one more time if don't understand
class Solution {
public:
    vector<int> nextSmallElem(vector<int>& arr) {
        // we store only indexes not real values
        stack<int> s;
        int n = arr.size();
        vector<int> nse(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                s.pop();
            }
            // if stack is empty store the last index else the top element
            nse[i] = s.empty() ? n : s.top();
            s.push(i); // current index is pushed
        }
        return nse;
    }
    vector<int> prevSmallElem(vector<int>& arr) {
        stack<int> s;
        vector<int> pse(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            // to skip the edge cases we also include the less then equal sign
            // it will not re calculate the duplicates again.
            while (!s.empty() && arr[i] <= arr[s.top()]) {
                s.pop();
            }
            // if stack is empty store -1 index else the top element
            pse[i] = (s.empty()) ? -1 : s.top();
            s.push(i); // current index is pushed
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long totalSum = 0;
        int mod = 1e9 + 7;
        vector<int> nse = nextSmallElem(arr);
        vector<int> pse = prevSmallElem(arr);
        // we have calculated the nse and psee
        for (int i = 0; i < arr.size(); i++) {
            // how many to the left are smaller
            long long left = i - pse[i];
            long long right = nse[i] - i;
            // calculate the total frequency to be add in the final value
            long long total = (left * right * arr[i] * 1LL) % mod;
            totalSum = (totalSum + total) % mod;
        }
        return totalSum;
    }
};