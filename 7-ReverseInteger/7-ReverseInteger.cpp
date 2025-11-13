// Last updated: 11/13/2025, 1:16:14 PM
// thinking to reduce the value so that it won't overflow.
// 1st way is modulation but it does not work as it (x + y)%m.
// 2nd way by using very large data types eg: double, float etc // but won't
// work 3rd way is using string but that is not running even that way.
// even try using the try catch blocks to catch any error into this it works but not that way.
#include <algorithm>
#include <string>

class Solution {
public:
    int reverse(int x) {
        // Big data type don't work here.
        if(x>=INT_MAX || x<=INT_MIN){
            return 0;
        }
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = 0 -x;
        }
        long long res = 0;
        int rem = 0;
        while (x != 0) {
            rem = x % 10;
            x = x / 10;
            if((res*10+rem)>INT_MAX){
                return 0;
            }else{
            res = res * 10 + rem;
            }
        }
        return (flag) ? int(-res) : int(res);

        // string method even won't work

        // string str = to_string(x);
        // int i = 0,j= str.length()-1;
        // while(i<j){
        //     char temp = str[i];
        //     str[i] = str[j];
        //     str[j] = temp;
        //     i++;
        //     j--;
        // }
        // if(flag){
        //     str = "-"+str;
        //     return stoi(str);
        // }
        // return stoi(str);

        // modulation methods is also not working

        // int m = 1e09;
        // bool flag = false;
        // if (x < 0) {
        //     flag = true;
        //     x = abs(x);
        // }
        // int res = 0;
        // int rem = 0;
        // while (x != 0) {
        //     rem = (x % 10) % m;
        //     x = (x / 10) % m;
        //     res = (((res % m) * 10) % m + rem) % m;
        // }
        // return (flag) ? -res : res;
    }
};