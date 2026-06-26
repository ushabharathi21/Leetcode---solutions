class MinStack {
   // stack<int>s1;
    //stack<int>s2;
   stack<pair<int,int>>s;

public:
    MinStack() {
       
    }
    
    void push(int x) {
        //s1.push(x);
        //s2.push((!s2.empty()&&s2.top()<x)?s2.top():x);
        int _min = (!s.empty()&&s.top().second<x)?s.top().second:x;
        s.push({x,_min});
         
    }
    
    void pop() {
       // s1.pop();
        //s2.pop();
        s.pop();
    }
    
    int top() {
        //return s1.top();
        return s.top().first;
    }
    
    int getMin() {
        //return s2.top();
        return s.top().second;
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