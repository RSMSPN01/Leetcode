// So first i was thinking that this question might use some sorting to it, but
// i can't figure out that on what basis i should apply sorting on, i need the
// samllest value to point (0,0)    // or maybe find all distance and sort them
// and return the smallest one i guess

// Approach 2 : So i know this question belongs to heap, but i don't get the
// idea why the formula is given, but then i realize i have two points though 1>
// given one 2> origin point, i can store the values in the max heap of size k
// and in the end just return the points

// The t.C for this is O(nlogk) and extra time to store back to array

class Solution {
public:
    double Ed(int x, int y) { // constant time function
        double result = sqrt((x * x) + (y * y));
        return result;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // for finding the smallest we need maxHeap
        // but we need to store the distance as well as point
        priority_queue<pair<double, vector<int>>> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            int xPoint = points[i][0];
            int yPoint = points[i][1];
            double distance = Ed(xPoint, yPoint);
            maxHeap.push({distance, points[i]}); // store like {2.343,[1,-2]} //
            cout<<"push"<<maxHeap.top().first<<endl;
            if (maxHeap.size() > k) {
                maxHeap.pop();
                cout<<"pop"<<maxHeap.top().first<<endl;
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};