// Last updated: 11/13/2025, 1:16:16 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        	int n1 = v1.size();
	int n2 = v2.size();
	// again call the function for the smaller vector.
	if(n2<n1) {
		return findMedianSortedArrays(v2,v1);
	}
	int leftSide = (n1+n2+1)/2; // elements to be stored in left leftSide
	bool isEven = false;
	if((n1+n2)%2 == 0) {
		isEven = true;
	}
    int start = 0,end = n1,mid1 = 0,mid2 = 0;
    while(start<=end){
        mid1 = start +(end-start)/2;
        mid2 = leftSide - mid1;
        int l1 = INT_MIN,l2 = INT_MIN,r1 = INT_MAX,r2 = INT_MAX;
        // just decide how to take these 
        (mid1 ==0)?l1 = INT_MIN:l1 = v1[mid1-1];
        (mid2 ==0)?l2 = INT_MIN:l2 = v2[mid2-1];
        (mid1 ==n1)?r1 = INT_MAX:r1 = v1[mid1];
        (mid2 ==n2)?r2 = INT_MAX:r2 = v2[mid2];
    
        if(l1<=r2 && l2<=r1){
            // it is a valid case we have got the answer
            if(isEven){
                return (double)(max(l1,l2)+min(r1,r2))/2;
            }else{
                return (double)max(l1,l2); // if the array is odd.
            }
        }
        if(l1>r2){
            end = mid1-1;
        }else{
            start = mid1+1;
        }
    }
    return 0;
    }
};