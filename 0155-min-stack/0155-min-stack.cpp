// Approach : So i am going to use a stack to perform all the operations on the
// stack that is simple, to implement minstack i am thinking to use a extra
// space which keeps the track of all the values one by one

// But i realize there is a problem in that if i use extra space, then that will
// always sort the current stack so even adding and removing the element will
// cost me O(n)

// or each time run a loop on stack till it is not empty and push the values
// from one stack to another while keep track of the min element in the end just
// return the min value

// I am not writting the code with extra space bcs, i know i can do this that
// way but the question asked us to solve the problem in constant time so let
// see some help, see what we can got

// After looking for help i get that we just need to create a extra stack which
// will keep the track of the current small value which we can use anytime
// Time.C = O(1), Space.C = O(n) so we can get the values in O(1) time 

class MinStack {
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minStack.empty()) {
            minStack.push(val); // if stack is already empty just push first value
        } else if (val < minStack.top()) {
            minStack.push(val); // if current val is smaller push it in first
        } else {
            minStack.push(minStack.top()); // repeat the same value
        }
    }

    void pop() {
        s.pop();
        minStack.pop(); // also pop this to make sure both have equal values
    }

    int top() {
        if (s.empty()) {
            return -1;
        }
        return s.top();
    }
    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top(); // just return it don't remove it
        // This is costly approax O(n + n)
        // int minValue = INT_MAX;
        // while (!s.empty()) {
        //     minValue = min(minValue, s.top());
        //     temp.push(s.top());
        //     s.pop();
        // }
        // // again copy back the values
        // while (!temp.empty()) {
        //     s.push(temp.top());
        //     temp.pop();
        // }
        // return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */