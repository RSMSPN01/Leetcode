// Naive Approach : So we could also do this using simple for loops, keep
// applying the loops again and again, but that can make the code more complex
// and time consuming

// Better Approach : So i can see three patterns in this question, i will just
// do as what the statement is saying me to do
// 1 -> if currnt value is same pop the last one also
// 2-> if currnt value is small then just continue
// 3-> if larger then keep on poping the values until we found some larger value
// or stack becomes empty itself or the same value appears check all three
// conditions

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> temp;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) { // asteroid moving to the other side
                int curr = abs(asteroids[i]); // make it positive to compare
                if (temp.empty() || temp.top() < 0) {
                    // push the negative values also and even if prev value is
                    // also negative then also push it in 
                    temp.push(asteroids[i]);
                }else if(curr < temp.top()){
                    continue;
                }
                 else if (temp.top() == curr) { // 1st step
                    temp.pop();
                } else { // 3rd step
                    while (!temp.empty() && temp.top() < curr && temp.top() > 0) {
                        temp.pop();
                    }
                    // check all three conditoins now
                    if (temp.empty()) {
                        temp.push(asteroids[i]); // push the curr value with sign
                    } else if (temp.top() == curr) {
                        temp.pop();
                    }else if(temp.top() > curr){
                        continue;
                    }
                    else{
                        temp.push(asteroids[i]);
                    }
                }
            } else {
                temp.push(asteroids[i]);
            }
        }
        // now store the values back to array
        int n = temp.size();
        vector<int> result(n);
        while (!temp.empty()) {
            result[n - 1] = temp.top();
            temp.pop();
            n--;
        }
        return result;
    }
};