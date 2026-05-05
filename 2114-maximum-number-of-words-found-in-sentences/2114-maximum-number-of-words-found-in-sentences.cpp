class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        // just return the max length, think of it as 2d array
        // return the length of the longest column
        int n = sentences.size();
        int maxLenght = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 0; j < sentences[i].size(); j++) {
                if (sentences[i][j] == ' ') {
                    // if space occur update the count
                    count++;
                }
            }
            // in the end compare and store max
            if (count > maxLenght) {
                maxLenght = count;
            }
        }
        return maxLenght;
    }
};