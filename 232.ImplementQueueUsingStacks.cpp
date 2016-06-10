/*
Implement the following operations of a queue using stacks.
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        sIn.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (sOut.empty())
        {
            while (!sIn.empty())
            {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
        sOut.pop();
    }

    // Get the front element.
    int peek(void) {
        if (sOut.empty())
        {
            while (!sIn.empty())
            {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
        return sOut.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sIn.empty() && sOut.empty();
    }
    
    std::stack<int> sIn;
    std::stack<int> sOut;
};
