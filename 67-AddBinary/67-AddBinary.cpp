// Last updated: 11/13/2025, 1:15:48 PM
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string s;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }
            s.push_back((sum & 1) + '0');
            carry = sum >> 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};