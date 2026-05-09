// Naive Approach : Start for any index and keep tracking back until we have
// found a smaller value then the current. Time.C = O(n*n), Space.C = O(1)

// Better Approach : I am thinking to use stack here and doing this using PSE
// But using direclty PSE here make no sense must have to look for some other
// way
// There is a way to use extra stack to keep the track of the pop elements but
// that will give TLE for sure, bcs it has already given that before.

// I can't think of any approach let seek some help now

// So i was wrong instead of PSE i need PGE so till which index the we can get
// valid answer so like where is the last greater element .

class StockSpanner {
public:
    // we will store two values together span and current price
    // and for every pop out value we will add the last span to it
    // instead of recalculating again, just add the last calculated span
    stack<pair<int, int>> s;
    StockSpanner() {}
    int next(int price) {
        // PGE
        int span = 1;
        while (!s.empty() && s.top().first <= price) {
            // add the last span value to the current
            // and pop the last value out
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */