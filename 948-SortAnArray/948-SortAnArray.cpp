// Last updated: 11/13/2025, 1:14:31 PM
class Solution {
public:
    void mergeArray(vector<int>&nums,int low,int mid,int high){
        int i = low,j = mid+1;
        vector<int>temp;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            nums[i+low] = temp[i];
        }
    }
   void mergeSort(vector<int>&nums,int low,int high){
        if(low<high){
            int mid = low+(high-low)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            mergeArray(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};