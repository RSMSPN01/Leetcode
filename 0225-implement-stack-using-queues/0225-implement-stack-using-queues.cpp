// Approach : Just doing what the question is telling me to do
// so i guess every other operation is going to be same in this only difficulty
// is this that i am not able to write the pop function

// i can do that in this way first store all the values and then remove the last
// value and then again store it back in the original queue this is what i am
// thinking
// let seek some help how others have done this.

// actually i was wrong we are directly storing the values in such way so that
// we can apply all the function in the one line command only
class MyStack {
private:
    // const int maxSize = 100;
    queue<int> q; // dynamic size queue
public:
    MyStack() {
        // this is just constructor of the class
    }

    void push(int x) {
        // do pre computation here only
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            // keep pushing the first value to last
            q.push(q.front());
            // remove from the front it is already stored in backward
            q.pop();
        }
    }

    int pop() {
        int value = q.front();
        q.pop();
        return value;
        // if (empty()) {
        //     return -1;
        // }
        // // change the value of back, create temp queue and store values
        // there. return q.back();
    }

    int top() {
        return q.front();
        // if (empty()) {
        //     return -1;
        // }
        // return q.back(); // return the last element
    }

    bool empty() {
        return q.empty();
        // if (q.size() == 0) {
        //     return true;
        // }
        // return false;
    }
};