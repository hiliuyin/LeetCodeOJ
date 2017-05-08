/*
Implement the following operations of a stack using queues.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

// solution 1: use two queues
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty()) {
            q2.push(x);
        }
        else {
            q1.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int result = q2.front();
            q2.pop();
            return result;
        }
        else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int result = q1.front();
            q1.pop();
            return result;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int result = q2.front();
            q1.push(result);
            q2.pop();
            return result;
        }
        else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int result = q1.front();
            q2.push(result);
            q1.pop();
            return result;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    std::queue<int> q1, q2;
};

// solution 2: use one queue
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que_.push(x);
        for (int i = 0, iEnd = que_.size()-1; i < iEnd; ++i) {
            que_.push(que_.front());
            que_.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = que_.front();
        que_.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return que_.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que_.empty();
    }

private:
    std::queue<int> que_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

