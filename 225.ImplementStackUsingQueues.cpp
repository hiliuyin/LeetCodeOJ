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

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (q1.empty()) q2.push(x);
        else q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop(); // the last one
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
    }

    // Get the top element.
    int top() {
        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int val = q2.front();
            q1.push(val);
            q2.pop();
            return val;
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int val = q1.front();
            q2.push(val);
            q1.pop();
            return val;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
    
    std::queue<int> q1;
    std::queue<int> q2;
};

