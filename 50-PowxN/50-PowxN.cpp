// Last updated: 12/10/2025, 11:47:00 AM
class Solution {
public:
// Try to solve the question using recursion later
    double myPow(double x, int n) {
        // working final code and i will also try to explain this 
        double res = 1.0;
        if(n<0){
            // it means we have to take x as 1/x rather then changing the n we are
            // changing the x itself 
            x = 1/x;
        }
        long newN = labs(n); // converting it from int to long even positive 
        // why because it will not give us error while computing the result
        while(newN != 0){
            if(newN & 1 ){
                res = res * x;
            }
            x = x * x;
            newN = newN >> 1;
        }
        return res;

        // this code which i have writen here works best for the almost all the test
        // cases except for the last two edge cases which were not handled by me
        // because i don't know how to do that :)

        // handling edge cases is the most important part here
        // if(x == 0){
        //     return 0.0;
        // }
        // if(x == 1){
        //     return 1.0;
        // }
        // if(n == INT_MIN || n== INT_MAX && x <= 1){
        //     return 0.0;
        // }
        // double res = 1;
        // bool flag = false;
        // if(n<0) {
        //     flag = true;
        //     n = -1* n;
        // }
        // while(n!= 0){
        //     if(n&1){
        //         res = res*x;
        //     }
        //     n = n>>1;
        //     x = x*x;
        // }
        // return (flag)?1/res:res;
    }
};