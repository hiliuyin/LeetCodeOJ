/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data_.emplace_back(x);
        if (data_.size() == 1)
        {
            min_.push(x);
        }
        else
        {
            if (x < getMin())
                min_.push(x);
            else
                min_.push(getMin());
        }
    }
    
    void pop() {
        if (!data_.empty())
        {
            data_.erase(data_.begin() + data_.size() - 1);
            min_.pop();
        }
    }
    
    int top() {
        if (data_.empty())
            return 0;
    
        return data_.back();
    }
    
    int getMin() {
        if (data_.empty())
            return 0;

        return min_.top();
    }
    
private:
    std::vector<int> data_;
    std::stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
