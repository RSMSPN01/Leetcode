// Last updated: 11/13/2025, 1:16:06 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0,j = height.size()-1,maxarea = 0;
        while(i<j){
            int h = min(height[i],height[j]);
            int w = j-i;
            int area = h*w;
            maxarea = max(maxarea,area);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxarea;
    }
};