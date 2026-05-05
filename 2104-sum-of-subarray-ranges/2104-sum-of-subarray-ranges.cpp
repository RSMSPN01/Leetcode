// Naive Approach : Find out all the possible sub arrays and then find the min
// and max and solve the question, but the Time.C = O(n^2), Space.C = O(1)
// I am thinking that this is somewhat related to the previous question

//  not able to think of any Solution lets seek some help online 
// Same approach as the last question just a little sign changed in this 
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
    vector<int> nextGreatElem(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> nse(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!s.empty() && arr[i] > arr[s.top()]) {
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
    vector<int> prevGreatElem(vector<int>& arr) {
        stack<int> s;
        vector<int> pse(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            // to skip the edge cases we also include the less then equal sign
            // it will not re calculate the duplicates again.
            while (!s.empty() && arr[i] >= arr[s.top()]) {
                s.pop();
            }
            // if stack is empty store -1 index else the top element
            pse[i] = (s.empty()) ? -1 : s.top();
            s.push(i); // current index is pushed
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
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
            long long total = left * right * arr[i] * 1LL;
            totalSum = totalSum + total;
        }
        return totalSum;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        long long totalSum = 0;
        int mod = 1e9 + 7;
        vector<int> nge = nextGreatElem(arr);
        vector<int> pge = prevGreatElem(arr);
        // we have calculated the nse and psee
        for (int i = 0; i < arr.size(); i++) {
            // how many to the left are smaller
            long long left = i - pge[i];
            long long right = nge[i] - i;
            // calculate the total frequency to be add in the final value
            long long total = left * right * arr[i];
            totalSum = totalSum + total;
        }
        return totalSum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMax(nums) - sumSubarrayMins(nums));
    }
};