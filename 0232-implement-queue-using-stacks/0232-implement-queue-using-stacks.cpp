// Approach : i am using the same approach as the previous one precompute the
// stack into queue so that all other operations can be perform in O(1) time
// but i am not able to think any approach without extra space approach to
// convert the stack into queue lets seek some help now

// so we actually have to use the extra space for this,
// Approach 1 : copy the vlaues of current stack into the new stack, then push
// the current value and copy back tha vlaues to original stack
// Time.C = O(n), Space.C = O(n)

// so there are two approaches in the first one the push operation cost us more
// but if we want to optimize the push operation then we need to make the other
// operations costly in that case we make the top and pop operation costly

// Approach 2 : It is also simple that if the output stack is empty then copy
// the elements from stack 1 and else we don't need to do so because the other
// stack is already in the correct order.
// The code writting can be even more improved but the point is not to improve
// the code structure but to understand that how the code is actually working
// what is the logic behind it

class MyQueue {
private:
    // stack<int> s;
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
        // constructor
    }

    void push(int x) {
        // Approach 2
        input.push(x);

        // Approach 1
        // stack<int> temp;
        // while (!s.empty()) {
        //     // till it is not empty put the values in other stack
        //     temp.push(s.top());
        //     s.pop();
        // }
        // // first push the current value
        // s.push(x);
        // // again copy back the stack
        // while (!temp.empty()) {
        //     s.push(temp.top());
        //     temp.pop();
        // }
    }

    int pop() {
        // Approach 2
        if (output.empty()) {
            // copy the elements
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int value = output.top();
            output.pop();
            return value;
        } else {
            // order is already maintained just directly pop out
            int value = output.top();
            output.pop();
            return value;
        }
        return -1;
        // Approach 1
        // int value = s.top();
        // s.pop();
        // return value;
    }

    int peek() {
        // Approach 2
        if (output.empty()) {
            // copy the elements
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        } else {
            // order is already maintained just directly pop out
            return output.top();
        }
        return -1;
        // return s.top();
    }
    bool empty() { return input.empty() && output.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */