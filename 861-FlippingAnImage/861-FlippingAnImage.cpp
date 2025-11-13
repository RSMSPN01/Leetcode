// Last updated: 11/13/2025, 1:14:37 PM
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            int j = n - 1;
            int k = 0;
            while (k <= j) {
                if (k == j) {
                    image[i][k] = !(image[i][k]);
                } else {
                    int temp = image[i][k];
                    image[i][k] = !(image[i][j]);
                    image[i][j] = !temp;
                }
                j--;
                k++;
            }
        }
        return image;
    }
};