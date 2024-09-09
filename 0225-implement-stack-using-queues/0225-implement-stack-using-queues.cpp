class MyStack {
public:
    vector<int>arr;
    int tp;
    MyStack() {
        tp=-1;
    }
    
    void push(int x) {
       arr.push_back(x);
       tp++;
    }
    
    int pop() {
        int x=arr[tp];
         arr.pop_back();
         tp--;
        return x;
    }
    
    int top() {
        return arr[tp];
    }
    
    bool empty() {
        return tp==-1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */