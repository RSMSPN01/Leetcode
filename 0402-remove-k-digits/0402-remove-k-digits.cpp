// Approach : I can't think of any approach, not even the brute force one to
// solve the problem but i have understand a pattern about the problem

// so if i kind of eliminate all the peaks from the string then i will be left
// with the smallest values possible
// And this is the approach which i am going to use now, removing peaks
// I guess my approach is just way too big with no sense but still i would love
// to explain it

// keep the track of peaks and store the peak in a different stack, once we
// found right amount of peaks, we then traverse backwards from there and remove
// the peaks from the actual string, then will check for any trailing zeros and
// if we traverse the whole string and stil not find any peak it means the array
// is sorted and we must remove directly the last k values

// now lets see how close i am to the solution
// i was really very close to the acutal code only difference was that i was
// handling many condition with if else but the code which i look was way more
// simpler but follow the same pattern which i was thinking, removing the peaks
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> mono;
        for (int i = 0; i < num.size(); i++) {
            // this will remove k peaks from the string
            while (!mono.empty() && k > 0 && num[i] < mono.top()) {
                mono.pop();
                k--;
            }
            mono.push(num[i]);
        }
        //  again check if any peaks were left or not, maybe string is sorted
        while (!mono.empty() && k > 0) {
            mono.pop();
            k--;
        }
        // check for edge cases
        if (mono.empty()) {
            return "0";
        }
        string res;
        while (!mono.empty()) {
            res += mono.top();
            mono.pop();
        }
        // remove any trailing zeros
        while (res.length() > 0 && res.back() == '0') {
            res.pop_back();
        }
        // again check maybe all the zeros were gone
        if (res.empty()) {
            return "0";
        }
        // just reverse and return the string as the final ans
        reverse(res.begin(), res.end());
        return res;
    }
};