// Approach : Start traversing from the back of the string and check each and
// every value if is even remove it if not break the loop and return the string
// itself

class Solution {
public:
    string largestOddNumber(string nums) {
        int n = nums.length();
        for (int i = n-1; i >= 0; i--) {
            // to turn into integer sub integer
            int val = nums[i] - '0';
            if(val & 1 ) {
                // it is odd then break
                // break;
                return nums.substr(0, i + 1);
            }
            // you don't have to do this now

            // else{
                // remove it 
                // using erase fun can make the T.C = O(n)
                // num.erase()
                // instead mark it as last element
                // idk why this happen in other ide this code works fine but here?
                // nums[i] = '\0';
                // so this don't work bcs \0 doesn't meant end of string in c++ 
                // but in c does so this is wrong just return the sub string from
                // 0 till last valid digit 
            //     return nums.substr(0, i + 1);
            // }
        }
        return "";   
    }
};