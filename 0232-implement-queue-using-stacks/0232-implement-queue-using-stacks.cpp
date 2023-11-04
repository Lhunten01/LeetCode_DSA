class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        if (empty()) {
            // Handle the error or return a specific value for an empty queue.
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int peek() {
        if (empty()) {
            // Handle the error or return a specific value for an empty queue.
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
