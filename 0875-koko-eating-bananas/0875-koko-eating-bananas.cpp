// Approach : So this question is really similiar to the book allocation problem which i have done
// so it uses a direct bs on the total number of bananas and it will keep on decreasing until we
// have found the minimum number to satisfy the given condtion

// so apply bs on banana if found a number which is valid store it and look for the further 
// number in the end return the last stored number
// i guess writing the valid function could be tricky

// Reason why my code is failing was i was also checking the time in the condtion of while loop
// which makes it wrong, why bcs if we have less speed then piles will get overed first and time
// was still not zero but the piles have already over that is why code was failing in this condi
// -tion while(i < piles.size() && time >0)

// Time complexity is O(totalBanana * log(maxBananas))
bool valid(int speed,vector<int>piles,int time) {
    // This the wrong way to find the answer.
    int totalH = 0;
    for(int i = 0;i<piles.size();i++) {
        totalH += (piles[i] + speed - 1) / speed;
        // this is equal to ceil ( pile[i] / speed ) 
        if(totalH > time){
            return false;
        }
    }
    return true;

    // why this fails is because i am trying to find the speed based on no of bananas
    // which is quite slow way to find i have to subtract one by one instead i can use
    // math divisions and find it based on the speed.

    // int i = 0;
    // // these two conditions must be followed for a valid speed
    // while(i < piles.size() ){
    //     if(piles[i] > speed) {
    //         piles[i] = piles[i] - speed;
    //     }else{
    //         i++;
    //     }
    //     time--;
    //     // we can also early check the time here as well and directly return false.
    //     // if(time<0){
    //     //     return false;
    //     // }
    // }
    // if(time >= 0){
    //     // if you have time left >= 0 it means you have eaten the bananas in time 
    //     return true;
    // }
    // return false;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end()); // better way to find max ele in vector
        int mid = 0;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(valid(mid,piles,h)) {
                // if mid is valid it means search for more miniumum speed 
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};