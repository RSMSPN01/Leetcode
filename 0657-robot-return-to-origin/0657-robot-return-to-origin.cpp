class Solution {
public:
    bool judgeCircle(string moves) {
        int xAxis = 0;
        int yAxis = 0;
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'U') {
                yAxis++;
            } else if (moves[i] == 'D') {
                yAxis--;
            } else if (moves[i] == 'L') {
                xAxis++;
            } else {
                xAxis--;
            }
        }
        return (xAxis == 0 && yAxis == 0) ? true : false;
    }
};