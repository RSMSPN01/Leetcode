// Approach : Using bs but why? bcs we have to return the minimum days and that day
// has some range from 1 to max(bloomDay) so we can apply bs on that and return the min

// I am not be able to think up for the valid condition how i am going to write it 
// lets watch the video for some help and then i will try again

// what i get to know from the video that my search was wrong i was starting the low
// from zero instead i need to start it from the very minimum day
// i also got the approach for solving the contigous problem
class Solution {
public:
    bool valid(int mid ,vector<int> bloomDay, int m, int k ){
        // what we can do here count the contigous no. of flower and then check in the 
        // end how many flowers can we make out of that
        int count = 0;
        int maxBouquet = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                count++;
            }else{
                // if contigous part break then check
                maxBouquet += count / k;
                // this will keep the count of bouquet we can make
                // reset the count 
                count = 0;
            }
        }
        maxBouquet += count/k;
        if(maxBouquet >= m){
            return true;
        }
        return false;
        // break this function into two part first part checks
        // even the required no of flowers are blossmed or not 
        // first part
        // int totalFlower = 0;
        // for(int flower : bloomDay){
        //     if(mid >= flower){
        //         totalFlower++;
        //     }
        // }
        // if(totalFlower < m*k){
        //     return false;
        //     // means there are not yet bloosomed to make a valid bouquet
        // }
        // Second Part : If desired no of flowers are blossmed then check
        // are they in contigous manner or not if yes then return true
        // array[i] <= mid contigous
        // int totalCount = 0;
        // for(int i = 0;i<bloomDay.size();i++){
        //     for(int j = i;j< i+ k;j++){
                
        //     }
        // }
        
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // handling edge case 
        // bcs to handle the overflow problem during multiplication type cast to long
        if((long)m*k > bloomDay.size()){
            return -1;
        }
        // look for the search space why we have choosen these
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid = 0;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(valid(mid,bloomDay,m,k)){
                // possibly could be the answer but we have to find the min
                // so continue to trim down the search space
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
// something is wrong with the valid function check and dry run that again 
// it is not returning false value for any of the cases check that later on 