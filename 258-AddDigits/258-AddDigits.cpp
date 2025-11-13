// Last updated: 11/13/2025, 1:15:13 PM
class Solution {
public:
    int addDigits(int num) {
        if(num<10){
            return num;
        }
        if((num%10)==0 && num<100){
            return num/10;
        }
        else{
            int result = 0;
            while(num>0){
                result += num%10;
                num/=10;
            }
            if(result>=10){
                return addDigits(result);
            }else{
                return result;
            }
        }
    }
};