// Last updated: 11/13/2025, 1:14:53 PM
class Solution {
public:
    string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string s = "";
    while(i>=0 || j>=0 || carry){
        int a = (i>=0)?num1[i--]-'0':0;
        int b = (j>=0)?num2[j--]-'0':0;
        int temp = a+b+carry;
        s= string(1,(temp%10)+ '0')+ s;
        carry = temp/10;
    }
    // reverse(s.begin(),s.end());
    return s;
    }
    };