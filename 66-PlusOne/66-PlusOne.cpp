// Last updated: 11/13/2025, 1:15:50 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]<9){
           digits[n-1]++;
           return digits;
        }
        else{
            int carry = 1;
            int temp = 0;
            for(int i =n-1;i>=0;i--){
                temp = digits[i]+carry;
                digits[i] = temp%10;
                carry = temp/10;
                if(carry==0){
                    break;
                }
            }
            if(carry){
                digits.insert(digits.begin(),carry);
            }
            return digits;
        }
    }
};