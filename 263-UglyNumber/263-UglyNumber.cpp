// Last updated: 11/13/2025, 1:15:11 PM
class Solution {
public:
    bool isUgly(int n) {
      if(n<=0){return false;}
      if(n==1){return true;}
      while(n>1){
        if(n%2==0){
            n/=2;
        }
        else if(n%3==0){
            n/=3;
        }
        else if(n%5==0){
            n/=5;
        }
        else{
            return false;
        }
      }
      return true;  
    }
};