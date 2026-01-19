// Approach : Exactly similarly approach like the flower question, similar kind of valid
// function as well 

class Solution {
public:
    bool valid(int weight,vector<int>& weights,int days) {
        int totalDays = 0;
        int countDays = 0;
        for (int i = 0; i < weights.size(); i++) {
            if(totalDays + weights[i] <= weight){
                totalDays += weights[i];
            }else{
                countDays++;
                totalDays = weights[i];
            }
            if(countDays > days){
                return false;
            }
        }
        if(totalDays > 0){
            countDays++;
        }
        if(countDays > days){
                return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // search space is important here 
        // now the lowest a ship can handle is the max weight in the belt
        // and max will be the total sum in the conveyor belt 
        int low = *max_element(weights.begin(),weights.end());
        int maxWeight = 0;
        for(int &i : weights) {
            maxWeight += i;
        }
        int high = maxWeight, mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if(valid(mid,weights,days)) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};