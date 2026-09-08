class MinStack {
public:
    stack<int> st;
    stack<int> minl;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) minl.push(val);
        else if (minl.top() >= val) minl.push(val);
        st.push(val);

    }
    
    void pop() {
        if (st.top() == minl.top()) minl.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minl.top();
    }
};
